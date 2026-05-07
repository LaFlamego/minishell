/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:37:56 by crevette          #+#    #+#             */
/*   Updated: 2026/05/07 12:42:50 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "exec.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

unsigned int	pipe_build(int *pipe_in, int *pipe_out)
{
	int	pipefd[2];

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return (1);
	}
	*pipe_in = pipefd[0];
	*pipe_out = pipefd[1];
	return (0);
}

void	fd_close_reset(int *pipein, int *pipeout, int *prevfd)
{
	if (pipein && *pipein >= 0)
	{
		close(*pipein);
		*pipein = -1;
	}
	if (pipeout && *pipeout >= 0)
	{
		close(*pipeout);
		*pipeout = -1;
	}
	if (prevfd && *prevfd >= 0)
	{
		close(*prevfd);
		*prevfd = -1;
	}
}

void	free_cmd_path(t_exec_ctx *exec)
{
	if (exec->cmd.path == NULL)
		return ;
	free(exec->cmd.path);
	exec->cmd.path = NULL;
}
