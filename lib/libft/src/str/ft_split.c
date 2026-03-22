/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:02:34 by Oery              #+#    #+#             */
/*   Updated: 2026/03/22 19:22:07 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include <stdlib.h>

static int	count_splits(char const *s, char c)
{
	int	splits;

	splits = 0;
	while (*s)
	{
		if (*s != c)
		{
			splits++;
			while (*s && *s != c)
				s++;
		}
		if (*s == '\0')
			break ;
		s++;
	}
	return (splits);
}

static char	*get_next_split(char **s, char c)
{
	char	*split;
	int		length;

	while (**s && **s == c)
		(*s)++;
	length = 0;
	while ((*s)[length] && (*s)[length] != c)
		length++;
	split = malloc((length + 1) * sizeof(char));
	if (split == NULL)
		return (NULL);
	ft_strlcpy(split, *s, length + 1);
	*s += length;
	return (split);
}

void	*free_splits(char **splits)
{
	int	i;

	i = 0;
	while (splits && splits[i])
	{
		free(splits[i]);
		i++;
	}
	free(splits);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	char	*current;
	int		splits;
	int		i;

	current = (char *)s;
	splits = count_splits(s, c);
	result = malloc((splits + 1) * sizeof(char **));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < splits)
	{
		result[i] = get_next_split(&current, c);
		if (result[i] == NULL)
		{
			while (i >= 0)
				free(result[i--]);
			free(result);
			return (NULL);
		}
		i++;
	}
	result[splits] = NULL;
	return (result);
}
