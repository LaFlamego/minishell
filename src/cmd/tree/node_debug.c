/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_debug.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 11:43:15 by Oery              #+#    #+#             */
/*   Updated: 2026/04/25 16:59:00 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./node.h"
#include "src/scanner/token/token.h"

// TODO: Add pipeline debug
// TODO: Add indent

static void	debug_tokens(t_array *tokens)
{
	size_t	i;

	if (!tokens)
		ft_printf("*tokens is NULL\n");
	i = 0;
	while (i < tokens->size)
	{
		ft_printf("Token: %p", tokens->data[i]);
		ft_printf("%s", token_to_string(tokens->data[i]));
		i++;
	}
}

static void	debug_command(t_list *head)
{
	size_t	i;
	t_list	*curr;

	if (!head)
		ft_printf("head is NULL\n");
	curr = head;
	i = 0;
	while (curr)
	{
		ft_printf("[%d] = ", i);
		debug_tokens(curr->content);
		ft_printf("\n");
		curr = curr->next;
	}
}

static void	debug_binary_op(t_cmd_node *n, t_bin_op_args *data)
{
	if (n->kind == OP_AND)
		ft_printf("AND");
	else
		ft_printf("OR");
	ft_printf("LEFT");
	node_debug(data->left);
	ft_printf("RIGHT");
	node_debug(data->right);
}

// static void	debug_pipeline(t_pipe_args *data)
// {
// }

void	node_debug(t_cmd_node *n)
{
	if (!n)
	{
		ft_printf("(null)");
		return ;
	}
	if (n->kind == COMMAND)
		debug_command(n->data);
	// if (n->kind == PIPELINE)
	// 	debug_pipeline(n->data);
	if (n->kind == OP_AND || n->kind == OP_OR)
		debug_binary_op(n, n->data);
}
