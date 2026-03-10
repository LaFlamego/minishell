/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:31:35 by Oery              #+#    #+#             */
/*   Updated: 2026/03/10 21:32:19 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

t_array	*ft_array_alloc(void)
{
	t_array	*arr;

	arr = malloc(sizeof(t_array));
	ft_bzero(arr, sizeof(t_array));
	return (arr);
}

void	ft_array_free(t_array *arr, void (*f)(void *))
{
	ft_array_foreach(arr, f);
	free(arr->data);
	arr->capacity = 0;
	arr->size = 0;
}

// TODO: Handle Down Sizing
// Add overflow guard
void	*ft_array_resize(t_array *arr, size_t size)
{
	void	*data;

	data = malloc(size * sizeof(void *));
	if (!data)
		return (NULL);
	if (arr->data)
	{
		ft_memmove(data, arr->data, arr->size * sizeof(void *));
		free(arr->data);
	}
	arr->data = data;
	arr->capacity = size;
	return (arr->data);
}

size_t	ft_array_push(t_array *arr, void *ptr)
{
	if (arr->size + 1 > arr->capacity)
	{
		if (arr->capacity == 0)
			arr->capacity = 1;
		if (!ft_array_resize(arr, arr->capacity * 2))
			return (0);
	}
	arr->data[arr->size] = ptr;
	(arr->size)++;
	return (arr->size);
}
