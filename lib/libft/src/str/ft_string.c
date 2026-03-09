/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:00:54 by Oery              #+#    #+#             */
/*   Updated: 2026/03/09 20:52:07 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_string_alloc(t_string *s, size_t size)
{
	s->length = 0;
	s->content = malloc(size);
	if (s->content == NULL)
	{
		s->capacity = 0;
		return (NULL);
	}
	ft_bzero(s->content, size);
	s->capacity = size;
	return (s->content);
}

char	*ft_string_realloc(t_string *s, size_t new_size)
{
	char	*new_string;

	new_string = malloc(new_size);
	if (!new_string)
		return (NULL);
	ft_bzero(new_string, new_size);
	ft_strlcpy(new_string, s->content, new_size);
	s->capacity = new_size;
	free(s->content);
	s->content = new_string;
	return (s->content);
}

t_string	ft_string_from_cstring(char *str)
{
	t_string	s;

	s.length = ft_strlen(str);
	s.capacity = 0;
	s.content = str;
	return (s);
}
