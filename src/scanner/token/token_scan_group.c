/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_scan_group.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 19:44:18 by Oery              #+#    #+#             */
/*   Updated: 2026/04/14 21:20:59 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../scanner.h"

t_token	*token_scan_group(t_scanner *s)
{
	s->start = s->current;
	if (!scanner_add_token(s, LEFT_PAREN))
		return (NULL);
	while (scanner_peek(s) && scanner_peek(s) != ')')
	{
		if (!token_scan(s))
			return (NULL);
		s->start = s->current;
	}
	if (scanner_peek(s) == '\0')
	{
		return (scanner_error('('));
	}
	scanner_advance(s);
	return (scanner_add_token(s, RIGHT_PAREN));
}
