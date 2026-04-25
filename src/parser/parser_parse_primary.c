/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse_primary.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 15:46:30 by Oery              #+#    #+#             */
/*   Updated: 2026/04/25 15:14:02 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"

// TODO: Do we need to free something here?
t_cmd_node	*parser_parse_primary(t_parser *p)
{
	t_cmd_node	*expr;

	if (parser_match(p, LEFT_PAREN))
	{
		expr = parser_parse_expr(p);
		if (!parser_check(p, LEFT_PAREN))
			return (NULL);
		return (expr);
	}
	if (parser_match_command(p))
	{
		expr = parser_parse_command(p);
		return (expr);
	}
	return (NULL);
}
