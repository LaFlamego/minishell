/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse_expr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 11:08:47 by Oery              #+#    #+#             */
/*   Updated: 2026/04/25 14:53:51 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"

enum e_kind	token_tokind(t_token *t);

t_cmd_node	*parser_parse_expr(t_parser *p)
{
	t_cmd_node	*expr;
	t_cmd_node	*right;
	t_token		*op;

	if (parser_match_redirection(p))
	{
		op = parser_previous(p);
		right = parser_parse_primary(p);
		expr = node_new_bin(NULL, token_tokind(op), right);
		return (expr);
	}
	else
	{
		expr = parser_parse_binary(p);
		return (expr);
	}
}
