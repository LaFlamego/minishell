/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:24:11 by Oery              #+#    #+#             */
/*   Updated: 2026/03/22 19:04:55 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		current = *lst;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}
