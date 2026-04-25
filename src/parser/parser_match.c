/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_match.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 10:20:27 by Oery              #+#    #+#             */
/*   Updated: 2026/04/25 21:17:25 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"

bool	parser_match_command(t_parser *p)
{
	if (parser_match(p, BLANK) || parser_match(p, STRING))
		return (true);
	if (parser_match(p, DOLLAR) || parser_match(p, STAR))
		return (true);
	return (false);
}

bool	parser_check_command(t_parser *p)
{
	if (parser_check(p, BLANK) || parser_check(p, STRING))
		return (true);
	if (parser_check(p, DOLLAR) || parser_check(p, STAR))
		return (true);
	return (false);
}

bool	parser_match_redirection(t_parser *p)
{
	if (parser_match(p, REDIRECT_IN) || parser_match(p, REDIRECT_IN_UNTIL))
		return (true);
	if (parser_match(p, REDIRECT_OUT) || parser_match(p, REDIRECT_OUT_APPEND))
		return (true);
	return (false);
}

bool	parser_match_binary(t_parser *p)
{
	if (parser_match(p, AND) || parser_match(p, OR))
		return (true);
	if (parser_match_redirection(p) || parser_match(p, PIPE))
		return (true);
	return (false);
}

bool	parser_match(t_parser *p, t_token_type type)
{
	if (type != BLANK)
	{
		while (parser_match(p, BLANK))
			;
	}
	if (parser_check(p, type))
	{
		parser_advance(p);
		return (true);
	}
	return (false);
}
