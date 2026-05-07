/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:39:11 by Oery              #+#    #+#             */
/*   Updated: 2026/05/07 21:26:28 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./expand.h"
#include "src/cmd/tree/word/word.h"
#include "src/env/env.h"
#include "src/utils/utils.h"
#include <stdlib.h>

// FIXME: Heredoc

// FIXME: Allocation can fail
// > needs to be handled
// > "?" is a valid key and should be readable
// FIXME: ft_string_push can fail

// FIXME: handle error from redirection functions
int	handle_redirection(t_word_part *part, t_exec_ctx *ctx, t_env *env)
{
	char		*arg;
	t_word		*target;
	t_word_part	*target_part;

	target = part->data;
	target_part = NULL;
	if (part->kind != WK_REDIRECT_IN_UNTIL && target)
	{
		target_part = target->content;
		if (target_part->kind == WK_FILES)
		{
			ft_dprintf(2, "minishell: *: ambiguous redirect\n");
			return (0);
		}
	}
	if (part->kind == WK_REDIRECT_IN)
	{
		arg = expand_target(part->data, env, false);
		redirect_in(arg, ctx);
	}
	if (part->kind == WK_REDIRECT_IN_UNTIL)
	{
		arg = expand_target(part->data, env, true);
		redirect_in_until(ctx, arg);
	}
	if (part->kind == WK_REDIRECT_OUT)
	{
		arg = expand_target(part->data, env, false);
		redirect_out(arg, ctx);
	}
	if (part->kind == WK_REDIRECT_OUT_APPEND)
	{
		arg = expand_target(part->data, env, false);
		redirect_out_append(arg, ctx);
	}
	return (1);
}

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
		t_exec_ctx *ctx)
{
	if (part->kind == WK_STRING && !ft_string_push_str(arg, part->data))
		return (0);
	if (part->kind == WK_FILES && !expand_files(argv, env))
		return (0);
	if (part->kind == WK_VARIABLE && !expand_variable(arg, part->data, env))
		return (0);
	if (part->kind >= WK_REDIRECT_IN && part->kind <= WK_REDIRECT_OUT_APPEND)
		return (handle_redirection(part, ctx, env));
	return (1);
}

int	expand_word(t_list *parts, t_array *argv, t_env *env, t_exec_ctx *ctx)
{
	t_string	*arg;
	t_list		*curr;

	arg = ft_string_new(0);
	curr = parts;
	if (!arg)
		return (0);
	while (curr)
	{
		if (!expand_part(curr->content, arg, argv, env, ctx))
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

// FIXME: handle array_push failures
t_array	*expand_command(t_word *words, t_env *env, t_exec_ctx *ctx)
{
	t_word	*curr;
	t_array	*argv;

	argv = ft_array_new();
	if (!argv)
		return (NULL);
	curr = words;
	while (curr)
	{
		if (!expand_word(curr->content, argv, env, ctx))
		{
			ft_array_free(argv, free);
			return (NULL);
		};
		curr = curr->next;
	}
	ft_array_push(argv, NULL);
	return (argv);
}
