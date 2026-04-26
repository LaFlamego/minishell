/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse_binary.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 13:05:53 by Oery              #+#    #+#             */
/*   Updated: 2026/04/26 16:04:06 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"

static enum e_kind	tokind(t_token *t)
{
	if (t->type == AND)
		return (OP_AND);
	if (t->type == OR)
		return (OP_OR);
	return (0);
}

static void	*error(t_cmd_node *expr)
{
	node_free(expr);
	return (NULL);
}

t_cmd_node	*parser_parse_binary(t_parser *p)
{
	t_cmd_node	*expr;
	t_token		*op;
	t_cmd_node	*right;

	expr = parser_parse_pipe(p);
	if (!expr)
		return (error(NULL));
	while (parser_match(p, AND) || parser_match(p, OR))
	{
		op = p->previous->content;
		right = parser_parse_pipe(p);
		if (!right)
			return (error(expr));
		expr = node_new_bin(expr, tokind(op), right);
	}
	return (expr);
}
