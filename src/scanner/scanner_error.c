/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 00:18:43 by Oery              #+#    #+#             */
/*   Updated: 2026/04/07 16:06:34 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./scanner.h"

// TODO: Print error message with current i
// > Should it be printed to stderr?
void	scanner_error(t_scanner *s, char expected, size_t current)
{
	char	found;

	found = s->source[current];
	ft_dprintf(2, "Syntax error: expected '%c' but found '%c'.\n", expected,
		found);
	return ;
}
