/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 23:36:59 by Oery              #+#    #+#             */
/*   Updated: 2026/03/14 23:37:30 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/string.h"
#include <stddef.h>

size_t	ft_string_push(t_string *s, char c)
{
	if (s->size + 1 > s->capacity)
	{
		if (s->capacity == 0)
			s->capacity = 1;
		if (!ft_string_resize(s, s->capacity * 2))
			return (0);
	}
	s->content[s->size] = c;
	s->size++;
	return (s->size);
}

// Does not NULL terminate
size_t	ft_string_push_str(t_string *s, const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
	{
		ft_string_push(s, str[i]);
		i++;
	}
	return (s->size);
}
