/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 18:54:56 by Oery              #+#    #+#             */
/*   Updated: 2026/03/13 18:12:23 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/list.h"
#include <stdlib.h>

t_list	*ft_lstpop_back(t_list **lst)
{
	t_list	*curr;
	t_list	*prev;

	if (*lst == NULL)
		return (NULL);
	curr = *lst;
	prev = *lst;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = NULL;
	return (curr);
}
