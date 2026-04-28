/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:39:11 by Oery              #+#    #+#             */
/*   Updated: 2026/04/28 23:16:06 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/cmd/tree/word/word.h"
#include "src/env/env.h"
#include "src/utils/utils.h"
#include <stdlib.h>

// TODO: expand the file, then setup the redirection
// > How to handle delimiters?
void	handle_redirection(void);

// TODO: filtering?
int	expand_files(t_array *argv, t_env *env)
{
	t_array		*files;
	char		*path;
	size_t		i;
	t_string	*file;

	path = env_get(env, "PWD");
	if (!path)
		return (0);
	files = dir_get_files(path);
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
	free(files);
	return (1);
}

int	expand_variable(t_string *arg, char *key, t_env *env)
{
	char	*value;

	value = env_get(env, key);
	if (!value)
		return (1);
	if (!ft_string_push_str(arg, value))
		return (0);
	return (1);
}

int	expand_part(t_word_part *part, t_string *arg, t_array *argv, t_env *env)
{
	if (part->kind == WK_STRING && !ft_string_push_str(arg, part->data))
		return (0);
	if (part->kind == WK_FILES && !expand_files(argv, env))
		return (0);
	if (part->kind == WK_VARIABLE && !expand_variable(arg, part->data, env))
		return (0);
	// if (part->kind >= WK_REDIRECT_IN && part->kind <= WK_REDIRECT_OUT_APPEND)
	// {
	// 	// TODO: handle redirection
	// }
	return (1);
}

int	expand_word(t_list *parts, t_array *argv, t_env *env)
{
	t_string	*arg;
	t_list		*curr;

	arg = ft_string_new(0);
	curr = parts;
	if (!arg)
		return (0);
	while (curr)
	{
		if (!expand_part(curr->content, arg, argv, env))
		{
			ft_string_free(arg);
			return (0);
		};
		curr = curr->next;
	}
	if (arg->size > 1 && !ft_array_push(argv, arg->content))
	{
		ft_string_free(arg);
		return (0);
	};
	free(arg);
	return (1);
}

t_array	*expand_command(t_word *words, t_env *env)
{
	t_word	*curr;
	t_array	*argv;

	argv = ft_array_new();
	if (!argv)
		return (NULL);
	curr = words;
	while (curr)
	{
		if (!expand_word(curr->content, argv, env))
		{
			ft_array_free(argv, free);
			return (NULL);
		};
		curr = curr->next;
	}
	return (argv);
}
