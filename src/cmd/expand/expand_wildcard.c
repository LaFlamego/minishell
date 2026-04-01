/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_wildcard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 12:44:46 by Oery              #+#    #+#             */
/*   Updated: 2026/04/02 01:24:58 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "src/env/env.h"
#include "src/files/files.h"

static void	*handle_error(t_string *expanded, t_array *files)
{
	if (expanded)
		ft_string_free(expanded);
	if (files)
		ft_array_free(files, ft_string_free);
	return (NULL);
}

static void	add_all(t_array *dst, t_array *src)
{
	size_t	i;

	i = 0;
	while (i < src->size)
	{
		ft_array_push(dst, src->data[i]);
		i++;
	}
}

// TODO: Files that do not match the pattern should be hidden
// TODO: read_key must be able to return an error
void	*cmd_expand_wildcard(t_env *env, t_array *words)
{
	t_string	*expanded;
	t_array		*files;
	char		*pwd;

	expanded = ft_string_new(0);
	if (!expanded)
		return (handle_error(expanded, NULL));
	pwd = env_get(env, "PWD=");
	if (!pwd)
		return (handle_error(expanded, NULL));
	files = dir_get_files(pwd);
	if (!files)
		return (handle_error(expanded, files));
	add_all(words, files);
	return (words);
}
