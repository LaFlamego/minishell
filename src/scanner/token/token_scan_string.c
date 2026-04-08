/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_scan_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 15:39:47 by Oery              #+#    #+#             */
/*   Updated: 2026/04/07 15:46:20 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../scanner.h"
#include "./token.h"

// TODO: check length calculation
// > start+1 and current-1 -> content inside the quotes
t_token	*token_scan_string(t_scanner *s)
{
	char	*text;

	while (scanner_peek(s) != '\'' && is_at_end(s))
	{
		scanner_advance(s);
	}
	if (is_at_end())
	{
		scanner_error(s);
		// TODO: Display Error
		return (NULL);
	}
	scanner_advance(s);
	text = ft_substr(s->source, s->start + 1, s->current - 1);
	scanner_add_token_lit(s, STRING, text);
}
