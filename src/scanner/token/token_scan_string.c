/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_scan_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 15:39:47 by Oery              #+#    #+#             */
/*   Updated: 2026/04/09 16:50:48 by Oery             ###   ########.fr       */
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
