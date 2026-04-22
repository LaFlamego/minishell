/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_track.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 20:24:51 by crevette          #+#    #+#             */
/*   Updated: 2026/04/22 19:53:15 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cmd.h"
# include "../tree/node.h"

void    track_nodes(t_cmd_node *node)
{
	t_bin_op_args	*ops;

	if (!node)
		return ;
	ops = node->data;
	if (node->kind == OP_AND || node->kind == OP_OR)
	{
		if (node->kind == OP_AND)
		{

		}
		if (node->kind == OP_OR)
		{
			
		}
		track_nodes(ops->left);
	}
	if (node->kind == PIPELINE)
	{

	}
	if (node->kind == COMMAND)
	{

	}
}
