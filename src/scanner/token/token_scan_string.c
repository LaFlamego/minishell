/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_scan_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 15:39:47 by Oery              #+#    #+#             */
/*   Updated: 2026/05/01 18:02:56 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../scanner.h"
#include "./token.h"
#include "stdlib.h"

// NOTE: Do we still need to differentiate strings/idents/dq/sq?

// FIXME: Treat symbols as strings separator
// a string can start with one but not end?

t_token	*token_scan_string(t_scanner *s)
{
	char	*text;

	while (scanner_peek(s) && scanner_peek(s) != '\'')
	{
		scanner_advance(s);
	}
	if (scanner_peek(s) == '\0')
	{
		return (scanner_error('\''));
	}
	scanner_advance(s);
	text = ft_substr(s->source, s->start + 1, s->current - s->start - 2);
	if (!text)
		return (NULL);
	return (scanner_add_token_lit(s, STRING, text));
}

static t_token	*scan_part(t_scanner *s)
{
	char	c;
	char	*ident;

	c = scanner_peek(s);
	while (c && c != '"')
	{
		if (c == '$' && is_valid_ident(scanner_peek_next(s)))
			break ;
		scanner_advance(s);
		c = scanner_peek(s);
	}
	ident = ft_substr(s->source, s->start, s->current - s->start);
	if (!ident)
		return (NULL);
	if (ft_streq(ident, "$"))
	{
		free(ident);
		return (scanner_add_token(s, DOLLAR));
	}
	return (scanner_add_token_lit(s, STRING, ident));
}

t_token	*token_scan_string_double(t_scanner *s)
{
	char	c;

	while (scanner_peek(s) && scanner_peek(s) != '"')
	{
		s->start = s->current;
		c = scanner_advance(s);
		if (c == '$' && is_valid_ident(scanner_peek(s)))
		{
			if (!scanner_add_token(s, DOLLAR))
				return (NULL);
			s->start = s->current;
			if (scanner_peek(s) != '$' && !token_scan_ident(s))
				return (NULL);
		}
		else
		{
			if (!scan_part(s))
				return (NULL);
		}
	}
	if (scanner_peek(s) == '\0')
	{
		return (scanner_error('"'));
	}
	scanner_advance(s);
	return ((t_token *)1);
}
