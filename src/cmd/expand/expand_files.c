/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 16:24:31 by Oery              #+#    #+#             */
/*   Updated: 2026/05/17 16:32:35 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "src/cmd/tree/word/word.h"
#include "src/env/env.h"
#include "src/utils/utils.h"
#include <stdlib.h>

char	*expand_filter(t_list *parts)
{
	t_string	*filter;
	t_word_part	*part;
	t_list		*curr;

	filter = ft_string_new(0);
	if (!filter)
		return (NULL);
	curr = parts;
	while (curr)
	{
		part = curr->content;
		if (part->kind == WK_STRING)
		{
			ft_string_push_str(filter, part->data);
		}
		if (part->kind == WK_FILES)
		{
			ft_string_push(filter, '*');
		}
		curr = curr->next;
	}
	return (ft_string_take(filter));
}

int	expand_files(t_array *argv, t_env *env, char *filter)
{
	t_array		*files;
	char		*path;
	size_t		i;
	t_string	*file;

	path = env_get(env, "PWD");
	if (!path)
		return (0);
	files = dir_get_files(path, filter);
	if (!files)
		return (0);
	i = 0;
	while (i < files->size)
	{
		file = files->data[i];
		if (!ft_array_push(argv, file->content))
		{
			ft_array_free(files, ft_string_free);
			return (0);
		}
		i++;
	}
	ft_array_free(files, free);
	return (1);
}
