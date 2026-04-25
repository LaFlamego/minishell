/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 11:01:42 by crevette          #+#    #+#             */
/*   Updated: 2026/04/25 15:00:02 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include "libft.h"
#include "cmd.h"
#include "../tree/node.h" 

unsigned int    handle_and_sign(t_cmd_node *node)
{
    t_bin_op_args	*op_node;
	unsigned int	exit_code;

	exit_code = 0;
	op_node = node->data;
	exit_code = track_nodes(op_node->left);
	if (exit_code != 0)
		return (exit_code);
	exit_code = track_nodes(op_node->right);
	return (exit_code);
}

unsigned int	handle_or_sign(t_cmd_node *node)
{
    t_bin_op_args	*op_node;
	unsigned int	exit_code;

	exit_code = 0;
	op_node = node->data;
	exit_code = track_nodes(op_node->left);
	if (exit_code == 0)
		return (exit_code);
	exit_code = track_nodes(op_node->right);
	return (exit_code);
}

unsigned int    handle_pipe_sign(t_cmd_node *node)
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
		pid_last = exec_pipeline(get_pipe, i);
		i++;
	}
	exit_code = wait_exit_code(pid_last);
	return (exit_code);
}

unsigned int	handle_input_sign()
{

}

unsigned int	handle_output_sign()
{

}

unsigned int	handle_heredoc_sign()
{

}

unsigned int	handle_append_sign()
{
	
}

void	handle_single_command()
{

}

