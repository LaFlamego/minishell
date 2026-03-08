/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 20:16:29 by Oery              #+#    #+#             */
/*   Updated: 2026/01/06 17:59:16 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_safe_assign(char **dst, char *src)
{
	if (*dst)
		free(*dst);
	*dst = src;
	return (*dst);
}

char	*ft_merge(char *dst, char *buf, int n)
{
	int		i;
	int		j;
	char	*result;
	int		len_dst;

	if (dst == NULL)
		return (ft_strldup(buf, n));
	len_dst = ft_strlen(dst);
	result = malloc(len_dst + n + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len_dst)
	{
		result[i] = dst[i];
		i++;
	}
	j = 0;
	while (j < n)
	{
		result[i + j] = buf[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

void	ft_lstpop(t_gnl_list **lst, int fd)
{
	t_gnl_list	*curr;
	t_gnl_list	*prev;

	if (*lst == NULL)
		return ;
	curr = *lst;
	prev = NULL;
	while (curr)
	{
		if (curr->fd == fd)
		{
			if ((*lst)->fd == fd)
				*lst = NULL;
			if (prev)
				prev->next = curr->next;
			else
				*lst = curr->next;
			if (curr->buf)
				free(curr->buf);
			free(curr);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}
