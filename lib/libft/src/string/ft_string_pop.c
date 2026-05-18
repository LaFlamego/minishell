/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_pop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 19:01:35 by Oery              #+#    #+#             */
/*   Updated: 2026/05/18 23:43:15 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mem/ft_mem.h"
#include "ft_string.h"

void	ft_string_pop(t_string *s, char *ptr)
{
	size_t	i;

	i = ptr - s->content;
	if (s->size <= 1 || ptr < s->content || ptr >= s->content + s->size)
		return ;
	if (i != s->size)
	{
		ft_memmove(ptr, ptr + 1, s->size - i);
	}
	s->size = s->size - 1;
}
