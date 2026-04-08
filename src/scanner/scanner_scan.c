/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner_scan.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 15:28:15 by Oery              #+#    #+#             */
/*   Updated: 2026/04/07 15:49:19 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./scanner.h"

char	scanner_advance(t_scanner *s)
{
	s->current++;
	return (s->source[s->current - 1]);
}

t_array	*scanner_scan(t_scanner *s)
{
	t_token	*eof;

	while (s->source[s->current])
	{
		s->start = s->current;
		token_scan(s);
	}
	eof = token_new(EOF, NULL);
	if (!eof || !ft_array_push(&s->tokens, eof))
		return (NULL);
	return (&s->tokens);
}

char	scanner_peek(t_scanner *s)
{
	if (s->source[s->current] == '\0')
		return ('\0');
	return (s->source[s->current]);
}

bool	scanner_match(t_scanner *s, char expected)
{
	char	c;

	c = s->source[s->current];
	if (c == '\0' || c != expected)
		return (false);
	s->current++;
	return (true);
}
