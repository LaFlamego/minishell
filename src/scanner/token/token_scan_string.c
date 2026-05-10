/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_scan_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 15:39:47 by Oery              #+#    #+#             */
/*   Updated: 2026/05/10 22:10:01 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../scanner.h"
#include "./token.h"
#include "stdlib.h"

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

// NOTE:
// If string starts with a symbol or a number
// It's length is 1
// Else read until blank / symbol

// FIXME: An empty string should not add any token

static t_token	*scan_dollar(t_scanner *s)
{
	char	*text;
	t_token	*t;

	if (s->current > s->start + 1)
	{
		text = ft_substr(s->source, s->start, s->current - s->start - 1);
		if (!text || !scanner_add_token_lit(s, STRING, text))
		{
			free(text);
			return (NULL);
		}
	}
	t = scanner_add_token_lit(s, DOLLAR, NULL);
	if (!t)
		return (NULL);
	s->start = s->current;
	if (scanner_peek(s) == '"' || scanner_peek(s) == ' ')
		return (t);
	return (token_scan_ident(s));
}

t_token	*token_scan_string_double(t_scanner *s)
{
	char	c;
	char	*text;
	t_token	*t;

	t = NULL;
	s->start = s->current;
	c = scanner_peek(s);
	while (c && c != '"')
	{
		if (scanner_match(s, '$'))
		{
			t = scan_dollar(s);
			if (!t)
				// FIXME: handle error
				return (NULL);
			s->start = s->current;
		}
		else
			scanner_advance(s);
		c = scanner_peek(s);
	}
	if (!scanner_match(s, '"'))
		return (scanner_error('"'));
	if (s->current > s->start)
	{
		text = ft_substr(s->source, s->start, s->current - s->start - 1);
		if (!text)
			return (NULL);
		return (scanner_add_token_lit(s, STRING, text));
	}
	return (t);
}
