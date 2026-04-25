/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ops_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:06:02 by crevette          #+#    #+#             */
/*   Updated: 2026/04/25 17:43:55 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "../tree/node.h"
#include <sys/types.h>

static unsigned int	wait_exit_code(pid_t pid_last)
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

unsigned int    handle_pipe_sign(t_cmd_node *node, t_fds *fd)
{
	t_pipe_args		*get_pipe;
	t_cmd_node		*pipe_node;
	pid_t			pid_last;
	unsigned int	exit_code;
	int				i;

	exit_code = 1;
	get_pipe = node->data;
	pipe_node = get_pipe->commands->data;
	i = 1;
	while (i <= get_pipe->commands->size)
	{
		pid_last = exec_pipeline(get_pipe, fd, i);
		i++;
	}
	exit_code = wait_exit_code(pid_last);
	return (exit_code);
}
