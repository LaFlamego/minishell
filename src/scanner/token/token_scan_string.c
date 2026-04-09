/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_scan_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 15:39:47 by Oery              #+#    #+#             */
/*   Updated: 2026/04/09 18:00:45 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../scanner.h"
#include "./token.h"

t_token	*token_scan_string(t_scanner *s)
{
	char	*text;

	while (scanner_peek(s) && scanner_peek(s) != '\'')
	{
		scanner_advance(s);
	}
	if (scanner_peek(s) == '\0')
	{
		return (scanner_error(s, '\''));
	}
	scanner_advance(s);
	text = ft_substr(s->source, s->start + 1, s->current - s->start - 2);
	return (scanner_add_token_lit(s, STRING, text));
}

static bool	is_valid_id(const char c)
{
	return (true);
}

static t_token	*scan_part(t_scanner *s)
{
	char	c;
	char	*ident;

	c = scanner_peek(s);
	while (is_valid_ident(c) || ft_isspace(c))
	{
		if (c == '$' && is_valid_ident(scanner_peek_next(s)))
			break ;
		scanner_advance(s);
		c = scanner_peek(s);
	}
	ident = ft_substr(s->source, s->start + 1, s->current - s->start - 1);
	return (scanner_add_token_lit(s, STRING, ident));
}

// "test$test" -> string dollar string
// "test$" -> string
//
// relevant characters are
// > End quote "
// > NULL Term
// > $Dollar
// -> so an ident except we don't care about spaces?

// TODO: add support for white spaces
// TODO: "$A(" should be a valid input
// > DOLLAR, A, "("
t_token	*token_scan_string_double(t_scanner *s)
{
	while (scanner_peek(s) && scanner_peek(s) != '"')
	{
		if (scanner_peek(s) == '$' && is_valid_ident(scanner_peek_next(s)))
		{
			// FIXME: can fail
			scanner_add_token(s, DOLLAR);
			scanner_advance(s);
		}
		else
		{
			// FIXME: can fail
			scan_part(s);
			s->start = s->current;
		}
	}
	if (scanner_peek(s) == '\0')
	{
		return (scanner_error(s, '"'));
	}
	scanner_advance(s);
	return (s->tokens.data[s->tokens.size]);
}
