/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse_expr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 11:08:47 by Oery              #+#    #+#             */
/*   Updated: 2026/04/26 18:43:28 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"

t_cmd_node	*parser_parse_expr(t_parser *p)
{
	t_cmd_node	*expr;
	t_token		*last;

	last = p->current->content;
	expr = parser_parse_binary(p);
	if (parser_match(p, LEFT_PAREN))
	{
		parser_error(last);
		return (node_free(expr));
	}
	return (expr);
}
