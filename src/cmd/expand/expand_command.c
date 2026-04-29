/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:39:11 by Oery              #+#    #+#             */
/*   Updated: 2026/04/29 15:03:02 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./expand.h"
#include "src/cmd/tree/word/word.h"
#include "src/env/env.h"
#include "src/utils/utils.h"
#include <stdlib.h>

// TODO: Can the file be in multiple part?
// like "test"something
// FIXME: handle errors
char	*expand_filepath(t_word_part *file, t_env *env)
{
	char	*expanded;

	if (file->kind == WK_STRING)
		return (file->data);
	expanded = env_get(env, file->data);
	return (expanded);
}

// TODO: expand the file, then setup the redirection
// > How to handle delimiters?

// FIXME: data must be expanded first
// FIXME: handle error from redirection functions
int	handle_redirection(t_word_part *part, t_fds *fds, t_env *env)
{
	if (part->kind == WK_REDIRECT_IN)
	{
		redirect_in(fds, expand_filepath(part->data, env));
	}
	if (part->kind == WK_REDIRECT_IN_UNTIL)
	{
		redirect_in_until(fds, expand_filepath(part->data, env));
	}
	if (part->kind == WK_REDIRECT_OUT)
	{
		redirect_out(expand_filepath(part->data, env));
	}
	if (part->kind == WK_REDIRECT_OUT_APPEND)
	{
		redirect_out_append(expand_filepath(part->data, env));
	}
	return (1);
}

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

int	expand_part(t_word_part *part, t_string *arg, t_array *argv, t_env *env,
		t_fds *fds)
{
	if (part->kind == WK_STRING && !ft_string_push_str(arg, part->data))
		return (0);
	if (part->kind == WK_FILES && !expand_files(argv, env))
		return (0);
	if (part->kind == WK_VARIABLE && !expand_variable(arg, part->data, env))
		return (0);
	if (part->kind >= WK_REDIRECT_IN && part->kind <= WK_REDIRECT_OUT_APPEND)
		return (handle_redirection(part, fds, env));
	return (1);
}

int	expand_word(t_list *parts, t_array *argv, t_env *env, t_fds *fds)
{
	t_string	*arg;
	t_list		*curr;

	arg = ft_string_new(0);
	curr = parts;
	if (!arg)
		return (0);
	while (curr)
	{
		if (!expand_part(curr->content, arg, argv, env, fds))
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

t_array	*expand_command(t_word *words, t_env *env, t_fds *fds)
{
	t_word	*curr;
	t_array	*argv;

	argv = ft_array_new();
	if (!argv)
		return (NULL);
	curr = words;
	while (curr)
	{
		if (!expand_word(curr->content, argv, env, fds))
		{
			ft_array_free(argv, free);
			return (NULL);
		};
		curr = curr->next;
	}
	return (argv);
}
