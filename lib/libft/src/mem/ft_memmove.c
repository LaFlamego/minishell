/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:23:45 by Oery              #+#    #+#             */
/*   Updated: 2025/11/13 22:17:58 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (n == 0)
		return (dest);
	if (dest > src)
	{
		n--;
		while (n > 0)
		{
			((unsigned char *) dest)[n] = ((unsigned char *) src)[n];
			n--;
		}
		((unsigned char *) dest)[0] = ((unsigned char *) src)[0];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *) dest)[i] = ((unsigned char *) src)[i];
			i++;
		}
	}
	return (dest);
}
