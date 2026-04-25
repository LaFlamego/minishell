/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 17:31:56 by Oery              #+#    #+#             */
/*   Updated: 2026/04/25 16:18:46 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./scanner.h"
#include <stdlib.h>

t_scanner	scanner_new(const char *source)
{
	t_scanner	s;

	ft_bzero(&s, sizeof(t_scanner));
	s.source = source;
	return (s);
}

t_scanner	*scanner_free(t_scanner *s)
{
	ft_lstclear(&s->tokens, &token_free);
	return (NULL);
}
