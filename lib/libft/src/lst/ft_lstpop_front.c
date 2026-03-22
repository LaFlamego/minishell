/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 18:50:31 by Oery              #+#    #+#             */
/*   Updated: 2026/03/22 19:12:19 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_lstpop_front(t_list **lst)
{
	t_list	*current;

	if (*lst)
	{
		current = *lst;
		*lst = (*lst)->next;
		current->next = NULL;
		return (current);
	}
	return (NULL);
}
