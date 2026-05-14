/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_scan_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 15:39:47 by Oery              #+#    #+#             */
/*   Updated: 2026/05/14 22:09:20 by Oery             ###   ########.fr       */
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

static int	traverse_string(t_scanner *s, t_token **t)
{
	char	c;

	c = scanner_peek(s);
	while (c && c != '"')
	{
		if (scanner_match(s, '$'))
		{
			*t = scan_dollar(s);
			if (!*t)
			{
				scanner_error('$');
				return (0);
			}
			s->start = s->current;
		}
		else
			scanner_advance(s);
		c = scanner_peek(s);
	}
	return (1);
}

t_token	*token_scan_string_double(t_scanner *s)
{
	char	*text;
	t_token	*t;

	t = NULL;
	s->start = s->current;
	if (!traverse_string(s, &t))
		return (NULL);
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
