/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_scan_ident.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 17:13:58 by Oery              #+#    #+#             */
/*   Updated: 2026/05/03 16:16:20 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../scanner.h"
#include <stdlib.h>

// TODO: Ident stop on symbol
// First char can be symbol

// TODO: Is Alnum?
// are underscore accepted?
bool	is_valid_ident(const char c)
{
	return (ft_isalnum(c));
	// if (c == '\0')
	// 	return (false);
	// if (c == '&' || c == '|')
	// 	return (false);
	// if (c == '<' || c == '>')
	// 	return (false);
	// if (c == '(' || c == ')')
	// 	return (false);
	// if (c == '\'' || c == '"')
	// 	return (false);
	// if (ft_isspace(c))
	// 	return (false);
	// if (c == '$')
	// 	return (false);
	// return (true);
}

// 	return (scanner_add_token(s, DOLLAR));
t_token	*token_scan_ident(t_scanner *s)
{
	char	c;
	char	*ident;

	// TODO: Check if first character is a symbol
	// can we just advance anyway?
	// c = scanner_peek(s);
	// scanner_advance(s);
	c = scanner_peek(s);
	while (c && is_valid_ident(c))
	{
		// if (c == '$' && is_valid_ident(scanner_peek_next(s)))
		// 	break ;
		scanner_advance(s);
		c = scanner_peek(s);
	}
	ident = ft_substr(s->source, s->start, s->current - s->start);
	if (!ident)
		return (NULL);
	return (scanner_add_token_lit(s, STRING, ident));
}
