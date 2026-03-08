/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:53:34 by Oery              #+#    #+#             */
/*   Updated: 2025/11/13 21:55:07 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *) big);
	i = 0;
	j = 0;
	while (i < len && big[i])
	{
		j = 0;
		while (i + j < len && big[i + j] == little[j])
		{
			if (big[i + j] == '\0' || little[j + 1] == '\0')
				return ((char *) big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
