/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 17:31:56 by Oery              #+#    #+#             */
/*   Updated: 2026/04/10 21:23:49 by Oery             ###   ########.fr       */
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
	size_t	i;
	t_token	*token;

	i = 0;
	while (i < s->tokens.size)
	{
		token = s->tokens.data[i];
		if (token->text)
		{
			free(token->text);
			token->text = NULL;
		}
		free(token);
		i++;
	}
	return (NULL);
}
