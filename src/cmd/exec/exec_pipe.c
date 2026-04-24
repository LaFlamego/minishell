/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 15:35:32 by crevette          #+#    #+#             */
/*   Updated: 2026/04/24 13:01:51 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include "libft.h"
#include "../cmd.h"
#include "../tree/node.h"

void	set_fd(t_ctx *ctx)
{
	if (ctx->cmd.nb == 1)
	{
		ctx->infile = open_file(ctx, ctx->infile);
		if (!ctx->infile.valid)
		{
			perror(ctx->args[1]);
			ctx->prev_fd = -1;
		}
		ctx->prev_fd = ctx->infile.fd;
	}
	else if (ctx->cmd.nb == ctx->argc - 3)
	{
		ctx->outfile = open_file(ctx, ctx->outfile);
		if (!ctx->outfile.valid)
			ctx->outfile.fd = -1;
		ctx->pipe_out = ctx->outfile.fd;
	}
	else if (ctx->is_hd && ctx->cmd.nb == 2)
		ctx->prev_fd = ctx->pipe_in;
}

static void	old_fd_redirect(t_ctx *ctx)
{
	int	in_fd;
	int	out_fd;

	in_fd = ctx->prev_fd;
	out_fd = ctx->pipe_out;
	if (in_fd != -1)
		to_dup(ctx, in_fd, true);
	if (out_fd == -1 && ctx->cmd.nb == ctx->argc - 3)
	{
		open_outfile(ctx, NULL, &out_fd);
		if (out_fd < 0)
		{
			perror(ctx->args[ctx->argc - 1]);
			fd_close_all(ctx);
			error_exit(NULL, ctx);
		}
	}
	if (out_fd != -1)
		to_dup(ctx, out_fd, false);
	fd_close_all(ctx);
	cmd_exect(ctx);
}

pid_t	child_exect(t_ctx *ctx)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		fd_close_all(ctx);
		error_exit("pid", ctx);
	}
	else if (pid == 0)
	{
		exit_bad_cmd(ctx);
		fd_redirect(ctx);
	}
	else
		(void)pid;
	return (pid);
}

pid_t	execute_pipeline(t_ctx *ctx)
{
	pid_t	pid; 

	pid = -1;
	set_fd(ctx);
	if (ctx->cmd.nb == 1 && !ctx->infile.valid)
		if_infile_invalid(ctx);
	else
	{
		if (ctx->cmd.nb != ctx->argc - 3)
			pipe_build(ctx);
		pid = child_exect(ctx);
	}
	if (pid > 0)
	{
		fd_close_reset(&ctx->pipe_out);
		if (ctx->prev_fd != -1)
			fd_close_reset(&ctx->prev_fd);
		ctx->prev_fd = ctx->pipe_in;
	}
	free_cmds_path(ctx);
	return (pid);
}

static void	cmd_exect(t_ctx *ctx)
{
	execve(ctx->cmd.path, ctx->cmd.cmds, ctx->envp);
	perror("execve");
	free_cmds_path(ctx);
	exit(1);
}

//! SEPERATE
void	pipe_build(t_pipe_fd *fd)
{
	int	pipefd[2];

	if (pipe(pipefd) == -1)
		perror("pipe");
	fd->pipe_in = pipefd[0];
	fd->pipe_out = pipefd[1];
}

void	fd_close_reset(int *pipein, int *pipeout, int *prevfd)
{
	if (pipein && *pipein >= 0)
	{
		close(pipein);
		pipein = -1;
	}
	if (pipeout && *pipeout >= 0)
	{
		close(pipeout);
		pipeout = -1;
	}
	if (prevfd && *prevfd >= 0)
	{
		close(prevfd);
		prevfd = -1;
	}
}

static void	to_dup(t_pipe_fd *fd, int fd_dup, bool is_pipe_in)
{
	int	dup;

	dup = -1;
	if (is_pipe_in)
		dup = dup2(fd_dup, STDIN_FILENO);
	else
		dup = dup2(fd_dup, STDOUT_FILENO);
	if (dup == -1)
	{
		fd_close_reset(fd->pipe_in, fd->pipe_out, fd->prev_fd);
		perror("dup");
	}
}

void	fd_proceed(t_pipe_fd *fd, size_t index)
{
	int	in_fd;
	int	out_fd;

	in_fd = fd->prev_fd;
	out_fd = fd->pipe_out;
	if (in_fd != -1 && index != 1)
		to_dup(fd, in_fd, true);
	if (out_fd != -1 && index != fd->args_nb)
		to_dup(fd, out_fd, false);
	fd_close_reset(fd->pipe_in, fd->pipe_out, fd->prev_fd);
}

pid_t	exec_pipeline(t_pipe_args *list, size_t index)
{
	pid_t			pid;
	t_pipe_fd		fd;

	pid = -1;
	fd.args_nb = list->commands->size;
	if (index != fd.args_nb)
		pipe_build(&fd);
	pid = fork();
	//! following is child
	if (pid < 0)
	{
		fd_close_reset(&fd.pipe_in, &fd.pipe_out, &fd.prev_fd);
		perror("pid");
	}
	if (pid == 0)
	{
		fd_proceed(&fd, index);
		track_nodes(list->commands->data[index - 1]);//execute command in track_nodes
	}
	if (pid > 0)
	{
		fd_close_reset(NULL, &fd.pipe_out, &fd.prev_fd);
		fd.prev_fd = fd.pipe_in;
	}
	return (pid);
}

unsigned int	wait_exit_code(pid_t pid_last)
{
	int					status;
	unsigned int		exit_code;
	pid_t				pid_wait;

	exit_code = 0;
	pid_wait = wait(&status);
	while (pid_wait > 0)
	{
		if (pid_wait == pid_last)
		{
			if (WIFEXITED(status))
				exit_code = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				exit_code = WTERMSIG(status) + 128;
		}
		pid_wait = wait(&status);
	}
	return (exit_code);
}
