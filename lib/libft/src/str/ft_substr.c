/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:16:38 by Oery              #+#    #+#             */
/*   Updated: 2026/03/22 19:23:13 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i;
	int		size;

	if (start >= ft_strlen(s))
		size = 1;
	else if (len < ft_strlen(s) - start)
		size = len + 1;
	else
		size = ft_strlen(s) - start + 1;
	sub = malloc(size * sizeof(char));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < size - 1)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[size - 1] = '\0';
	return (sub);
}
