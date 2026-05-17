/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 22:48:44 by Oery              #+#    #+#             */
/*   Updated: 2026/05/17 17:35:06 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_array.h"

bool	is_sorted(t_array *arr, bool (*cmp)(void *a, void *b))
{
	size_t	i;

	i = 1;
	while (i < arr->size)
	{
		if (cmp(arr->data[i - 1], arr->data[i]) > 0)
			return (false);
		i++;
	}
	return (true);
}

void	ft_swap(void **a, void **b)
{
	void	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_array_sort(t_array *arr, int (*cmp)(void *a, void *b))
{
	size_t	i;
	size_t	j;
	bool	swapped;

	if (arr->size < 2)
		return ;
	i = 0;
	while (i < arr->size - 1)
	{
		j = 0;
		swapped = false;
		while (j < arr->size - i - 1)
		{
			if (cmp(arr->data[j], arr->data[j + 1]) > 0)
			{
				ft_swap(&arr->data[j], &arr->data[j + 1]);
				swapped = true;
			}
			j++;
		}
		if (swapped == false)
			break ;
		i++;
	}
}
