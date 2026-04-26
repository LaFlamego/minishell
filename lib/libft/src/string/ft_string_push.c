/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 23:36:59 by Oery              #+#    #+#             */
/*   Updated: 2026/04/26 12:01:46 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
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
	s->content[s->size - 1] = c;
	s->content[s->size] = '\0';
	s->size++;
	return (s->size);
}

size_t	ft_string_push_str(t_string *s, const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
	{
		if (!ft_string_push(s, str[i]))
			return (0);
		i++;
	}
	return (s->size);
}

size_t	ft_string_push_string(t_string *dst, const t_string *src)
{
	size_t	i;

	i = 0;
	while (i < src->size && src->content[i])
	{
		if (!ft_string_push(dst, src->content[i]))
			return (0);
		i++;
	}
	return (dst->size);
}

t_string	*ft_string_join(const t_array *parts)
{
	t_string	*s;
	t_string	*part;
	size_t		i;

	s = ft_string_new(0);
	if (!s)
		return (NULL);
	i = 0;
	while (i < parts->size)
	{
		part = parts->data[i];
		if (!ft_string_push_string(s, part))
		{
			ft_string_free(s);
			return (NULL);
		}
		i++;
	}
	return (s);
}
