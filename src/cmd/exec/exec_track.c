/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_track.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 20:24:51 by crevette          #+#    #+#             */
/*   Updated: 2026/04/23 23:46:23 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cmd.h"
# include "../tree/node.h"

//TODO < > << >>

unsigned int	track_nodes(t_cmd_node *node)
{
	if (!node)
		return(1);
	if (node->kind == OP_AND || node->kind == OP_OR)
	{
		if (node->kind == OP_AND)
			handle_and_sign(node);
		if (node->kind == OP_OR)
			handle_or_sign(node);
	}
	if (node->kind == PIPELINE)
		handle_pipe_sign(node);
	if (node->kind == COMMAND)
		handle_single_command(node);
}
