/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_iter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 20:01:00 by Oery              #+#    #+#             */
/*   Updated: 2026/03/13 17:53:12 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/array.h"
#include <stdlib.h>

void	ft_array_foreach(t_array *arr, void (*f)(void *))
{
	size_t	i;

	if (!f)
		return ;
	i = 0;
	while (i < arr->size)
	{
		f(arr->data[i]);
		i++;
	}
}

void	*ft_array_find(t_array *arr, bool (*f)(void *))
{
	size_t	i;

	i = 0;
	while (i < arr->size)
	{
		if (f(arr->data[i]))
			return (arr->data + i);
		i++;
	}
	return (NULL);
}
