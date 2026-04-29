/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 15:35:32 by crevette          #+#    #+#             */
/*   Updated: 2026/04/29 22:22:22 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include "libft.h"
#include "../cmd.h"
#include "../tree/node.h"

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

void	pipe_build(t_exec_ctx *exec_ctx)
{
	int	pipefd[2];

	if (pipe(pipefd) == -1)
		perror("pipe");
	exec_ctx->pipe.in = pipefd[0];
	exec_ctx->pipe.out = pipefd[1];
}

static void	pipeline_dup(t_exec_ctx *exec_ctx, int fd_dup, bool is_pipe_in)
{
	int	dup;

	dup = -1;
	if (is_pipe_in)
		dup = dup2(fd_dup, STDIN_FILENO);
	else
		dup = dup2(fd_dup, STDOUT_FILENO);
	if (dup == -1)
	{
		fd_close_reset(exec_ctx->pipe.in, exec_ctx->pipe.out, exec_ctx->prev_fd);
		perror("dup");
	}
}

static void	fd_proceed(t_exec_ctx *exec_ctx)
{
	int	in_fd;
	int	out_fd;

	in_fd = exec_ctx->prev_fd;
	out_fd = exec_ctx->pipe.out;
	if (in_fd != -1 && exec_ctx->pipe.index != 1)
		pipeline_dup(exec_ctx, in_fd, true);
	if (out_fd != -1 && exec_ctx->pipe.index != exec_ctx->args_nb)
		pipeline_dup(exec_ctx, out_fd, false);
	fd_close_reset(exec_ctx->pipe.in, exec_ctx->pipe.out, exec_ctx->prev_fd);
}

pid_t	exec_pipeline(t_list *list, t_exec_ctx *exec_ctx)
{
	pid_t			pid;

	pid = -1;
	//TODO (?)if prev_fd == -1?
	exec_ctx->prev_fd = STDIN_FILENO;
	if (exec_ctx->pipe.index != exec_ctx->args_nb)
		pipe_build(&exec_ctx);
	pid = fork();
	if (pid < 0)
	{
		fd_close_reset(&exec_ctx->pipe.in, &exec_ctx->pipe.out, &exec_ctx->prev_fd);
		perror("pid");
	}
	if (pid == 0)
	{
		fd_proceed(exec_ctx, exec_ctx->pipe.index);
		track_node(list->content);
	}
	if (pid > 0)
	{
		fd_close_reset(NULL, &exec_ctx->pipe.out, &exec_ctx->prev_fd);
		exec_ctx->prev_fd = exec_ctx->pipe.in;
	}
	return (pid);
}
