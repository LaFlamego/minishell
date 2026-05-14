/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 21:48:03 by Oery              #+#    #+#             */
/*   Updated: 2026/05/14 21:51:06 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./node.h"
#include "./word/word.h"
#include <stdlib.h>

static void	node_free_lst(void *node_raw)
{
	node_free(node_raw);
}

static void	node_free_binary(t_cmd_node *node)
{
	t_bin_op_args	*lr;

	lr = node->data;
	if (lr->left)
		node_free(lr->left);
	if (lr->right)
		node_free(lr->right);
	free(node->data);
}

t_cmd_node	*node_free(t_cmd_node *node)
{
	if (!node)
		return (NULL);
	if (!node->data)
	{
		free(node);
		return (NULL);
	}
	if (node->kind == OP_AND || node->kind == OP_OR)
	{
		node_free_binary(node);
	}
	if (node->kind == COMMAND)
	{
		ft_lstclear((t_list **)&node->data, &word_free);
	}
	if (node->kind == PIPELINE)
	{
		ft_lstclear((t_list **)&node->data, &node_free_lst);
	}
	free(node);
	return (NULL);
}
