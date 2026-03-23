/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_pop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 19:01:35 by Oery              #+#    #+#             */
/*   Updated: 2026/03/23 19:12:26 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mem/ft_mem.h"
#include "ft_string.h"

// FIXME: What happens if we pop the last char (aka the null term) ?
void	ft_string_pop(t_string *s, char *ptr)
{
	size_t	i;

	i = ptr - s->content;
	if (s->size == 0 || ptr < s->content || ptr > s->content + s->size)
		return ;
	if (i != s->size)
	{
		ft_memmove(ptr, ptr + 1, s->size - i);
	}
	s->size = s->size - 1;
}
