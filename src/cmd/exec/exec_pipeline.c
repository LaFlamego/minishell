/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 15:35:32 by crevette          #+#    #+#             */
/*   Updated: 2026/04/25 15:12:32 by crevette         ###   ########.fr       */
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

static void	pipe_build(t_pipe_fd *fd)
{
	int	pipefd[2];

	if (pipe(pipefd) == -1)
		perror("pipe");
	fd->pipe_in = pipefd[0];
	fd->pipe_out = pipefd[1];
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

static void	fd_proceed(t_pipe_fd *fd, size_t index)
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
