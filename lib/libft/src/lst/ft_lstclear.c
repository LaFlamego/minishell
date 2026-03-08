/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:32:57 by Oery              #+#    #+#             */
/*   Updated: 2025/11/13 20:21:27 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*to_delete;

	current = *lst;
	while (current)
	{
		to_delete = current;
		current = current->next;
		ft_lstdelone(to_delete, del);
	}
	*lst = NULL;
}
