/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_scan_ident.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 17:13:58 by Oery              #+#    #+#             */
/*   Updated: 2026/04/09 16:29:43 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../scanner.h"

bool	is_valid_ident(const char c)
{
	if (c == '\0')
		return (false);
	if (c == '&' || c == '|')
		return (false);
	if (c == '<' || c == '>')
		return (false);
	if (c == '(' || c == ')')
		return (false);
	if (c == '{' || c == '}')
		return (false);
	if (ft_isspace(c))
		return (false);
	return (true);
}

t_token	*token_scan_ident(t_scanner *s)
{
	char	c;
	char	*ident;

	c = scanner_peek(s);
	while (is_valid_ident(c))
	{
		if (c == '$' && !ft_isspace(scanner_peek_next(s)))
			break ;
		scanner_advance(s);
		c = scanner_peek(s);
	}
	ident = ft_substr(s->source, s->start, s->current - s->start);
	return (scanner_add_token_lit(s, IDENT, ident));
}
