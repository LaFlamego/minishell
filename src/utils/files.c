/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:26:04 by Oery              #+#    #+#             */
/*   Updated: 2026/05/17 18:16:50 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.h"
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

static bool	is_hidden(const char *name, const char *filter)
{
	if (ft_streq(name, ".") || ft_streq(name, ".."))
		return (true);
	return (ft_startswith(name, ".") && *filter != '.');
}

static t_string	*ft_to_string(const char *str)
{
	t_string	*s;

	s = ft_string_new(0);
	if (!s || !ft_string_push_str(s, str))
	{
		ft_string_free(s);
		return (NULL);
	}
	return (s);
}

// FIXME: to_string can fail
// FIXME: push can fail
static t_array	*get_file_list(DIR *dir, char *filter)
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
		if (!is_hidden(ent->d_name, filter) && is_filtered(ent->d_name, filter))
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

t_array	*dir_get_files(const char *path, char *filter)
{
	DIR		*dir;
	t_array	*files;

	dir = opendir(path);
	if (!dir)
		return (handle_error(dir, NULL));
	files = get_file_list(dir, filter);
	if (!files)
		return (handle_error(dir, files));
	closedir(dir);
	files_sort(files);
	return (files);
}
