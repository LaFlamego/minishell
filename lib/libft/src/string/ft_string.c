/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:00:54 by Oery              #+#    #+#             */
/*   Updated: 2026/03/16 19:00:08 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft/string.h"
#include <stdlib.h>

t_string	ft_string_init(void)
{
	t_string	s;

	s.capacity = 0;
	s.content = NULL;
	s.size = 0;
	return (s);
}

char	*ft_string_alloc(t_string *s, size_t size)
{
	s->size = 0;
	s->content = malloc(size);
	if (s->content == NULL && size != 0)
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

	s.size = ft_strlen(str);
	s.capacity = 0;
	s.content = str;
	return (s);
}

t_string	ft_string_from_cstring_alloc(char *str)
{
	t_string	s;

	s.size = ft_strlen(str) + 1;
	s.capacity = s.size;
	s.content = ft_strdup(str);
	return (s);
}

void	*ft_string_resize(t_string *s, size_t size)
{
	void	*data;

	data = malloc(size);
	if (!data)
		return (NULL);
	if (s->content)
	{
		ft_memmove(data, s->content, s->size);
		free(s->content);
	}
	s->content = data;
	s->capacity = size;
	return (s->content);
}
