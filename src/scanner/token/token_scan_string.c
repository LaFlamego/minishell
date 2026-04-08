/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_scan_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 15:39:47 by Oery              #+#    #+#             */
/*   Updated: 2026/04/08 17:13:33 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../scanner.h"
#include "./token.h"

// TODO: check length calculation
// > start+1 and current-1 -> content inside the quotes
t_token	*token_scan_string(t_scanner *s)
{
	char	*text;

	while (scanner_peek(s) != '\'' && scanner_peek(s) != '\0')
	{
		scanner_advance(s);
	}
	if (scanner_peek(s) == '\0')
		return (scanner_error(s, '\'', s->current));
	scanner_advance(s);
	text = ft_substr(s->source, s->start + 1, s->current - 1);
	return (scanner_add_token_lit(s, STRING, text));
}
