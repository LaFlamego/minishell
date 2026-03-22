/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 13:34:36 by Oery              #+#    #+#             */
/*   Updated: 2026/03/22 19:22:00 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../char/ft_char.h"
#include "ft_str.h"
#include <stdlib.h>

static char	*alloc_split(const char *s)
{
	char	*split;
	size_t	len;

	len = 0;
	while (s[len] && !ft_isspace(s[len]))
		len++;
	split = malloc(len + 1);
	if (!split)
		return (NULL);
	ft_strlcpy(split, s, len + 1);
	split[len] = '\0';
	return (split);
}

static const char	*next_split(const char *s)
{
	while (*s && ft_isspace(*s))
		s++;
	return (s);
}

t_array	*ft_split_space(const char *s)
{
	t_array	*splits;
	char	*split;

	splits = ft_array_alloc();
	if (!splits)
		return (NULL);
	s = next_split(s);
	while (s && *s)
	{
		split = alloc_split(s);
		if (!split || !ft_array_push(splits, split))
		{
			ft_array_free(splits, &free);
			return (NULL);
		}
		s += ft_strlen(split);
		s = next_split(s);
	}
	return (splits);
}
