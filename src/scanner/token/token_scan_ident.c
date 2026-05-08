/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_scan_ident.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 17:13:58 by Oery              #+#    #+#             */
/*   Updated: 2026/05/08 20:20:57 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../scanner.h"
#include "libft.h"
#include <stdlib.h>

static bool	is_still_valid(const char c)
{
	return (ft_isalpha(c) || ft_isdigit(c) || c == '_');
}

t_token	*token_scan_ident(t_scanner *s)
{
	char	c;
	char	*ident;

	c = scanner_peek(s);
	if (ft_isalpha(c) || c == '_')
	{
		while (c && is_still_valid(c))
		{
			scanner_advance(s);
			c = scanner_peek(s);
		}
	}
	else
		scanner_advance(s);
	ident = ft_substr(s->source, s->start, s->current - s->start);
	if (!ident)
		return (NULL);
	return (scanner_add_token_lit(s, STRING, ident));
}
