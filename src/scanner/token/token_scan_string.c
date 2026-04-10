/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_scan_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 15:39:47 by Oery              #+#    #+#             */
/*   Updated: 2026/04/10 16:03:40 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../scanner.h"
#include "./token.h"

// FIXME: substr can fail
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
	return (scanner_add_token_lit(s, STRING, text));
}

// FIXME: substr can fail
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
	return (scanner_add_token_lit(s, STRING, ident));
}

// WARN: Watch out for multiple dollarsigns
t_token	*token_scan_string_double(t_scanner *s)
{
	char	c;

	while (scanner_peek(s) && scanner_peek(s) != '"')
	{
		s->start = s->current;
		c = scanner_advance(s);
		if (c == '$' && is_valid_ident(scanner_peek(s)))
		{
			// FIXME: can fail
			scanner_add_token(s, DOLLAR);
			s->start = s->current;
			// FIXME: can fail
			if (scanner_peek(s) != '$')
				token_scan_ident(s);
		}
		else
		{
			// FIXME: can fail
			scan_part(s);
		}
	}
	if (scanner_peek(s) == '\0')
	{
		return (scanner_error('"'));
	}
	scanner_advance(s);
	return ((t_token *)1);
}
