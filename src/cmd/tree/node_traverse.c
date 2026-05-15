/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_traverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 16:29:09 by Oery              #+#    #+#             */
/*   Updated: 2026/05/15 16:51:42 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./node.h"
#include "libft.h"

static int	traverse_pipe(t_cmd_node *node, int (*fn)(t_cmd_node *node))
{
	t_list	*curr;

	curr = node->data;
	while (curr)
	{
		if (!node_traverse(curr->content, fn))
			return (0);
		curr = curr->next;
	}
	return (1);
}

static int	traverse_bin(t_cmd_node *node, int (*fn)(t_cmd_node *node))
{
	t_bin_op_args	*args;

	args = node->data;
	if (!fn(args->left))
	{
		return (0);
	}
	if (!fn(args->right))
	{
		return (0);
	}
	return (1);
}

int	node_traverse(t_cmd_node *node, int (*fn)(t_cmd_node *node))
{
	if (!fn(node))
	{
		return (0);
	}
	if (node->kind == PIPELINE)
	{
		return (traverse_pipe(node, fn));
	}
	if (node->kind == OP_AND || node->kind == OP_OR)
	{
		return (traverse_bin(node, fn));
	}
	return (1);
}
