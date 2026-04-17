/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:21:36 by Oery              #+#    #+#             */
/*   Updated: 2026/04/17 12:42:39 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./node.h"
#include <stdlib.h>

static void	*node_alloc_args(t_cmd_node *node)
{
	size_t	size;

	if (node->kind == COMMAND)
		size = sizeof(t_cmd_args);
	if (node->kind == OP_AND || node->kind == OP_OR)
		size = sizeof(t_bin_op_args);
	if (node->kind == PIPELINE)
		size = sizeof(t_pipe_args);
	node->data = malloc(size);
	if (!node->data)
		return (NULL);
	ft_bzero(node->data, size);
	return (node->data);
}

t_cmd_node	*node_new(enum e_kind kind)
{
	t_cmd_node	*node;

	node = malloc(sizeof(t_cmd_node));
	if (!node)
		return (NULL);
	ft_bzero(node, sizeof(t_cmd_node));
	node->kind = kind;
	node->data = node_alloc_args(node);
	if (!node->data)
		return (node_free(node));
	return (node);
}

// free the node pointer and its content
// TODO: Free command and pipeline
t_cmd_node	*node_free(t_cmd_node *node)
{
	t_bin_op_args	*lr;

	if (!node)
		return (NULL);
	if (!node->data)
	{
		free(node);
		return (NULL);
	}
	if (node->kind == OP_AND || node->kind == OP_OR)
	{
		lr = node->data;
		node_free(lr->left);
		node_free(lr->right);
	}
	// if (node->kind == COMMAND)
	// {
	//
	// }
	// if (node->kind == PIPELINE)
	// {
	//
	// }
	free(node->data);
	free(node);
	return (NULL);
}
