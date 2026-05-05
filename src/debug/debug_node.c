/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 11:43:15 by Oery              #+#    #+#             */
/*   Updated: 2026/05/05 01:14:26 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./debug.h"

void	debug_node_redirect(t_word_part *node, size_t depth)
{
	debug_indent(depth);
	ft_printf("> REDIRECT [%d]\n", node->kind);
	debug_indent(depth);
	ft_printf("== Value:\n");
	debug_words(node->data, depth + 1);
}

static void	debug_command(t_list *words, size_t depth)
{
	t_list	*curr;

	if (!words)
		ft_printf("head is NULL\n");
	debug_indent(depth);
	ft_printf("> COMMAND\n");
	curr = words;
	while (curr)
	{
		debug_words(curr->content, depth + 1);
		curr = curr->next;
	}
}

static void	debug_binary_op(t_cmd_node *n, t_bin_op_args *data, size_t depth)
{
	if (n->kind == OP_AND)
	{
		debug_indent(depth);
		ft_printf("> AND\n");
	}
	else
	{
		debug_indent(depth);
		ft_printf("> OR\n");
	}
	debug_indent(depth);
	ft_printf("== LEFT\n");
	debug_node(data->left, depth + 1);
	debug_indent(depth);
	ft_printf("== RIGHT\n");
	debug_node(data->right, depth + 1);
}

static void	debug_pipeline(t_list *commands, size_t depth)
{
	t_list	*curr;

	debug_indent(depth);
	ft_printf("> PIPELINE\n");
	curr = commands;
	while (curr)
	{
		debug_node(curr->content, depth + 1);
		curr = curr->next;
	}
}

void	debug_node(t_cmd_node *n, size_t depth)
{
	if (!n)
	{
		debug_indent(depth);
		ft_printf("> (null)\n");
		return ;
	}
	if (n->kind == COMMAND)
		debug_command(n->data, depth);
	if (n->kind == PIPELINE)
		debug_pipeline(n->data, depth);
	if (n->kind == OP_AND || n->kind == OP_OR)
		debug_binary_op(n, n->data, depth);
}
