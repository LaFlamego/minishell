/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:04:47 by Oery              #+#    #+#             */
/*   Updated: 2026/05/03 17:39:54 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 64

// TODO: If realloc fails, is buf set to NULL?
char	*get_pwd(void)
{
	t_string	*buf;
	char		*path;

	buf = ft_string_new(BUFFER_SIZE);
	if (!buf)
		return (NULL);
	while (getcwd(buf->content, buf->capacity) == NULL && errno == ERANGE)
	{
		if (!ft_string_realloc(buf, buf->capacity * 2))
			return (NULL);
	}
	if (errno && !buf->content)
		return (NULL);
	path = buf->content;
	free(buf);
	return (path);
}
