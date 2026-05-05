/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse_primary.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 15:46:30 by Oery              #+#    #+#             */
/*   Updated: 2026/05/01 15:23:54 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"

t_cmd_node	*parser_parse_primary(t_parser *p)
{
	t_cmd_node	*expr;

	if (parser_match(p, LEFT_PAREN))
	{
		expr = parser_parse_expr(p);
		if (!expr)
			return (NULL);
		if (!parser_match(p, RIGHT_PAREN))
		{
			parser_error(parser_peek(p));
			return (node_free(expr));
		}
		return (expr);
	}
	if (parser_check_command(p))
		return (parser_parse_command(p));
	parser_error(parser_peek(p));
	return (NULL);
}
