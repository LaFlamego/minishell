/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_scan_blank.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 16:11:22 by Oery              #+#    #+#             */
/*   Updated: 2026/04/09 16:39:58 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../scanner.h"

t_token	*token_scan_blank(t_scanner *s)
{
	char	c;

	c = scanner_peek(s);
	while (c && ft_isspace(c))
	{
		scanner_advance(s);
		c = scanner_peek(s);
	}
	return (scanner_add_token(s, BLANK));
}
