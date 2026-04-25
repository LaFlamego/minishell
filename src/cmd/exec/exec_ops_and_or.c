/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ops_and_or.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 11:01:42 by crevette          #+#    #+#             */
/*   Updated: 2026/04/25 15:13:35 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cmd.h"
#include "../tree/node.h" 

unsigned int    handle_and_sign(t_cmd_node *node)
{
    t_bin_op_args	*op_node;
	unsigned int	exit_code;

	exit_code = 0;
	op_node = node->data;
	exit_code = track_node(op_node->left);
	if (exit_code != 0)
		return (exit_code);
	exit_code = track_node(op_node->right);
	return (exit_code);
}

unsigned int	handle_or_sign(t_cmd_node *node)
{
    t_bin_op_args	*op_node;
	unsigned int	exit_code;

	exit_code = 0;
	op_node = node->data;
	exit_code = track_node(op_node->left);
	if (exit_code == 0)
		return (exit_code);
	exit_code = track_node(op_node->right);
	return (exit_code);
}

