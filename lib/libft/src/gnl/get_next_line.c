/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:16:10 by Oery              #+#    #+#             */
/*   Updated: 2026/02/01 19:16:02 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

char	*ft_safe_assign(char **dst, char *src);
char	*ft_merge(char *dst, char *buf, int n);
void	ft_lstpop(t_gnl_list **lst, int fd);

#ifndef BUFFER_SIZE

# define BUFFER_SIZE 42

#endif

static t_gnl_list	*ft_lstfnd_or_new(t_gnl_list **lst, int fd)
{
	t_gnl_list	*curr;
	t_gnl_list	*new;

	curr = *lst;
	while (curr)
	{
		if (curr->fd == fd)
			return (curr);
		if (curr->next == NULL)
			break ;
		curr = curr->next;
	}
	new = malloc(sizeof(t_gnl_list));
	if (new == NULL)
		return (NULL);
	new->fd = fd;
	new->buf = NULL;
	new->next = NULL;
	if (curr)
	{
		curr->next = new;
		return (curr->next);
	}
	*lst = new;
	return (*lst);
}

static char	*get_new_line(char *s, int n)
{
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while ((n == -1 || i < n) && s[i])
	{
		if (s[i] == '\n')
			return (s + i + 1);
		i++;
	}
	return (NULL);
}

static ssize_t	try_read(t_gnl_list *e, char **next)
{
	char	r_buf[BUFFER_SIZE];
	ssize_t	n;

	n = read(e->fd, r_buf, BUFFER_SIZE);
	if (n == 0)
	{
		*next = e->buf;
		e->buf = NULL;
	}
	else if (n > 0
		&& ft_safe_assign(&(e->buf), ft_merge(e->buf, r_buf, n)) == NULL)
		return (-1);
	return (n);
}

static int	get_buf_next_line(char **buf, char **next)
{
	char	*nl;

	if (*buf == NULL)
		return (0);
	nl = get_new_line(*buf, -1);
	if (!nl)
		return (0);
	if (*nl == '\0')
	{
		if (ft_safe_assign(next, *buf) == NULL)
			return (1);
		*buf = NULL;
		return (0);
	}
	if (ft_safe_assign(next, ft_strldup(*buf, nl - *buf)) == NULL)
		return (1);
	if (ft_safe_assign(buf, ft_strldup(nl, ft_strlen(nl))) == NULL)
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	static t_gnl_list	*lst = NULL;
	t_gnl_list			*entry;
	char				*next;

	next = NULL;
	entry = ft_lstfnd_or_new(&lst, fd);
	if (!entry)
		return (NULL);
	while (!next)
	{
		if (get_buf_next_line(&(entry->buf), &next))
		{
			ft_lstpop(&lst, fd);
			free(next);
			return (NULL);
		}
		if (!next && try_read(entry, &next) <= 0)
		{
			ft_lstpop(&lst, fd);
			return (next);
		}
	}
	if (entry && entry->buf == NULL)
		ft_lstpop(&lst, fd);
	return (next);
}
