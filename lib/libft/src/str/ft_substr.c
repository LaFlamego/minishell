/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:16:38 by Oery              #+#    #+#             */
/*   Updated: 2025/11/13 22:03:15 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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
