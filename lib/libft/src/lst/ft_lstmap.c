/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:02:17 by Oery              #+#    #+#             */
/*   Updated: 2026/03/13 18:11:14 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/list.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*current;
	void	*content;

	new = NULL;
	while (lst)
	{
		content = f(lst->content);
		if (content == NULL)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		current = ft_lstnew(content);
		if (current == NULL)
		{
			ft_lstclear(&new, del);
			if (del)
				del(content);
			return (NULL);
		}
		ft_lstadd_back(&new, current);
		lst = lst->next;
	}
	return (new);
}
