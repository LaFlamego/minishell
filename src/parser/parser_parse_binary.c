/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse_binary.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 13:05:53 by Oery              #+#    #+#             */
/*   Updated: 2026/04/25 21:38:42 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"

enum e_kind	token_tokind(t_token *t);

t_cmd_node	*parser_parse_binary(t_parser *p)
{
	t_cmd_node	*expr;
	t_token		*op;
	t_cmd_node	*right;

	expr = parser_parse_pipe(p);
	if (!expr)
		return (NULL);
	while (parser_match(p, AND) || parser_match(p, OR))
	{
		op = p->previous->content;
		right = parser_parse_pipe(p);
		if (!right)
		{
			node_free(expr);
			return (NULL);
		}
		expr = node_new_bin(expr, token_tokind(op), right);
	}
	return (expr);
}
