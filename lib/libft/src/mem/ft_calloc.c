/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:07:17 by Oery              #+#    #+#             */
/*   Updated: 2025/11/14 16:48:41 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdint.h>

void	*ft_calloc(size_t n, size_t size)
{
	void	*result;

	if (n != 0 && size > SIZE_MAX / n)
		return (NULL);
	result = malloc(n * size);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, n * size);
	return (result);
}
