/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:52:26 by Oery              #+#    #+#             */
/*   Updated: 2026/03/22 19:23:06 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include <stdlib.h>

static int	ft_has_char(char const *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static int	trimmed_len(char const *s1, char const *set)
{
	int	length;
	int	i;

	length = ft_strlen(s1);
	i = length - 1;
	while (ft_has_char(set, s1[i--]))
		length--;
	i = 0;
	while (ft_has_char(set, s1[i++]))
		length--;
	if (length < 0)
		return (0);
	return (length);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		length;
	char	*result;

	length = trimmed_len(s1, set);
	result = malloc(length + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (ft_has_char(set, s1[i]))
		i++;
	ft_strlcpy(result, s1 + i, length + 1);
	return (result);
}
