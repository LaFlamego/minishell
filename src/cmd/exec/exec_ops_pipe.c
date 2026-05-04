/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ops_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:06:02 by crevette          #+#    #+#             */
/*   Updated: 2026/05/04 18:23:17 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
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

static size_t	get_list_size(t_list *list)
{
	size_t	size;

	size = 0;
	while (list->content)
	{
		list = list->next;
		size++;
	}
	return (size);
}
unsigned int    handle_pipe_sign(t_cmd_node *node, t_exec_ctx *exec_ctx)
{
	t_list			*pipe_node;
	pid_t			pid_last;
	unsigned int	exit_code;
	size_t				size;

	exit_code = 1;
	pipe_node = node->data;
	size = get_list_size(pipe_node);
	exec_ctx->args_nb = size;
	exec_ctx->pipe.index = 1;
	while (exec_ctx->pipe.index <= size)
	{
		pid_last = exec_pipeline(pipe_node, exec_ctx);
		exec_ctx->pipe.index++;
		pipe_node = pipe_node->next;
	}
	exit_code = wait_exit_code(pid_last);
	return (exit_code);
}
