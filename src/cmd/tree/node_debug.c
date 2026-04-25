/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_debug.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 11:43:15 by Oery              #+#    #+#             */
/*   Updated: 2026/04/25 18:24:24 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./node.h"
#include "src/scanner/token/token.h"

// TODO: Add pipeline debug
// TODO: Add indent

static void	indent(size_t lvl)
{
	size_t	i;

	i = 0;
	while (i < lvl)
	{
		ft_printf("    ");
		i++;
	}
}

static void	debug_tokens(t_list *tokens, size_t depth)
{
	t_list	*curr;
	t_token	*t;

	if (!tokens)
	{
		indent(depth);
		ft_printf("*tokens is NULL\n");
	}
	curr = tokens;
	while (curr)
	{
		t = curr->content;
		indent(depth);
		ft_printf("Token: %p\n", t);
		indent(depth);
		ft_printf("== KIND: %s\n", token_to_string(t));
		if (t->type == STRING)
		{
			indent(depth);
			ft_printf("== VALUE: %s\n", t->text);
		}
		curr = curr->next;
	}
	ft_printf("\n");
}

static void	debug_command(t_list *head, size_t depth)
{
	t_list	*curr;
	size_t	i;

	if (!head)
		ft_printf("head is NULL\n");
	indent(depth);
	ft_printf("COMMAND\n");
	curr = head;
	i = 0;
	while (curr)
	{
		indent(depth);
		ft_printf("[%d]\n", i);
		debug_tokens(curr->content, depth + 1);
		curr = curr->next;
		i++;
	}
}

static void	debug_binary_op(t_cmd_node *n, t_bin_op_args *data, size_t depth)
{
	if (n->kind == OP_AND)
	{
		indent(depth);
		ft_printf("AND\n");
	}
	else
	{
		indent(depth);
		ft_printf("OR\n");
	}
	indent(depth + 1);
	ft_printf("== LEFT\n");
	node_debug(data->left, depth + 2);
	indent(depth + 1);
	ft_printf("== RIGHT\n");
	node_debug(data->right, depth + 2);
}

// static void	debug_pipeline(t_pipe_args *data)
// {
// }

void	node_debug(t_cmd_node *n, size_t depth)
{
	if (!n)
	{
		ft_printf("(null)");
		return ;
	}
	if (n->kind == COMMAND)
		debug_command(n->data, depth);
	// if (n->kind == PIPELINE)
	// 	debug_pipeline(n->data);
	if (n->kind == OP_AND || n->kind == OP_OR)
		debug_binary_op(n, n->data, depth);
}
