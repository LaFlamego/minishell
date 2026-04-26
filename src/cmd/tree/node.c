/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:21:36 by Oery              #+#    #+#             */
/*   Updated: 2026/04/26 16:00:29 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./node.h"
#include "src/scanner/token/token.h"
#include <stdlib.h>

static void	*node_alloc_args(t_cmd_node *node)
{
	size_t	size;

	size = sizeof(t_bin_op_args);
	node->data = malloc(size);
	if (!node->data)
		return (NULL);
	ft_bzero(node->data, size);
	return (node->data);
}

t_cmd_node	*node_new(enum e_kind kind)
{
	t_cmd_node	*node;

	node = ft_calloc(1, sizeof(t_cmd_node));
	if (!node)
		return (NULL);
	node->kind = kind;
	if (node->kind == COMMAND || node->kind == PIPELINE)
		return (node);
	node->data = node_alloc_args(node);
	if (!node->data)
		return (node_free(node));
	return (node);
}

t_cmd_node	*node_new_bin(t_cmd_node *left, enum e_kind op, t_cmd_node *right)
{
	t_cmd_node		*node;
	t_bin_op_args	*args;

	node = node_new(op);
	if (!node)
		return (NULL);
	args = node->data;
	args->left = left;
	args->right = right;
	return (node);
}

// t_cmd_node	*node_new_string(char *text)
// {
// 	t_cmd_node	*word;
//
// 	word = node_new(WK_STRING);
// 	if (!word)
// 		return (NULL);
// 	word->data = ft_string_new(ft_strlen(text));
// 	if (!word->data || !ft_string_push_str(word->data, text))
// 		return (node_free(word));
// 	return (word);
// }

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
