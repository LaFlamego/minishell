/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 18:50:31 by Oery              #+#    #+#             */
/*   Updated: 2026/01/23 22:31:48 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
