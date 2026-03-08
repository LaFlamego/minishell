/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:48:36 by Oery              #+#    #+#             */
/*   Updated: 2025/11/12 22:44:45 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*sc;

	sc = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (sc[i] == (unsigned char) c)
			return ((void *) s + i);
		i++;
	}
	return (NULL);
}
