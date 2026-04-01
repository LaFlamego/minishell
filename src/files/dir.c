/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:26:04 by Oery              #+#    #+#             */
/*   Updated: 2026/03/27 13:30:26 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

static void	*handle_error(DIR *dir, t_array *files)
{
	if (dir)
		closedir(dir);
	if (files)
		free(files);
	return (NULL);
}

static bool	is_hidden(const char *name)
{
	return (name && *name == '.');
}

static t_string	*ft_to_string(const char *str)
{
	t_string	*s;

	s = ft_string_new(0);
	if (!s)
		return (NULL);
	s->size = ft_strlen(str) + 1;
	s->capacity = s->size;
	s->content = ft_strdup(str);
	if (!s->content)
	{
		free(s);
		return (NULL);
	}
	return (s);
}

static t_array	*get_file_list(DIR *dir)
{
	struct dirent	*ent;
	t_array			*files;
	t_string		*name;

	files = ft_array_new();
	if (!files)
		return (NULL);
	ent = readdir(dir);
	while (ent)
	{
		if (!is_hidden(ent->d_name))
		{
			name = ft_to_string(ent->d_name);
			ft_array_push(files, name);
		}
		ent = readdir(dir);
	}
	if (errno)
	{
		ft_printf("minishell: readdir: %s\n", strerror(errno));
		return (NULL);
	}
	return (files);
}

t_array	*dir_get_files(const char *path)
{
	DIR		*dir;
	t_array	*files;

	dir = opendir(path);
	if (!dir)
		return (handle_error(dir, NULL));
	files = get_file_list(dir);
	if (!files)
		return (handle_error(dir, files));
	closedir(dir);
	return (files);
}
