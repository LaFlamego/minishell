/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 19:24:44 by Oery              #+#    #+#             */
/*   Updated: 2026/05/08 20:04:50 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"
#include <stdlib.h>

static t_cmd_node	*into_pipe(t_cmd_node *expr)
{
	t_cmd_node	*pipe;
	t_list		*new;

	if (expr->kind == PIPELINE)
		return (expr);
	pipe = node_new(PIPELINE);
	if (!pipe)
	{
		node_free(expr);
		return (NULL);
	}
	new = ft_lstnew(expr);
	if (!new)
	{
		node_free(expr);
		node_free(pipe);
		return (NULL);
	}
	ft_lstadd_back((t_list **)&pipe->data, new);
	return (pipe);
}

static void	*push_to_pipe(t_cmd_node *expr, t_cmd_node *right)
{
	t_list	*new;

	expr = into_pipe(expr);
	if (!expr)
	{
		node_free(right);
		return (NULL);
	}
	new = ft_lstnew(right);
	if (!new)
	{
		node_free(right);
		node_free(expr);
		return (NULL);
	}
	ft_lstadd_back((t_list **)&expr->data, new);
	return (expr);
}

// TODO: Pushtopipe can fail
t_cmd_node	*parser_parse_pipe(t_parser *p)
{
	t_cmd_node	*right;
	t_cmd_node	*expr;

	expr = parser_parse_primary(p);
	if (!expr)
		return (NULL);
	while (parser_match(p, PIPE))
	{
		right = parser_parse_primary(p);
		if (!right)
			return (node_free(expr));
		expr = push_to_pipe(expr, right);
	}
	return (expr);
}
