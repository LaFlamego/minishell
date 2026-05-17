/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 16:09:55 by Oery              #+#    #+#             */
/*   Updated: 2026/05/17 19:49:50 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./expand.h"
#include "./src/cmd/exec/exec.h"
#include "./src/cmd/tree/word/word.h"
#include <stdlib.h>

static bool	has_string(t_list *parts)
{
	t_list		*curr;
	t_word_part	*part;

	curr = parts;
	while (curr)
	{
		part = curr->content;
		if (part->kind == WK_STRING)
			return (true);
		curr = curr->next;
	}
	return (false);
}

static bool	is_file_list(t_list *parts)
{
	t_list		*curr;
	t_word_part	*part;
	bool		has_wildcard;

	has_wildcard = false;
	curr = parts;
	while (curr)
	{
		part = curr->content;
		if (part->kind == WK_VARIABLE)
			return (false);
		if (part->kind == WK_FILES)
			has_wildcard = true;
		curr = curr->next;
	}
	return (has_wildcard);
}

int	expand_part(t_word_part *part, t_string *arg, t_exec_ctx *ctx)
{
	if (part->kind == WK_STRING && !ft_string_push_str(arg, part->data))
		return (0);
	if (part->kind == WK_VARIABLE && !expand_variable(arg, part->data,
			ctx->env))
		return (0);
	if (part->kind >= WK_REDIRECT_IN && part->kind <= WK_REDIRECT_OUT_APPEND)
		return (expand_redirection(part, ctx));
	return (1);
}

static t_string	*expand_parts(t_list *parts, t_exec_ctx *ctx)
{
	t_list		*curr;
	t_string	*arg;

	arg = ft_string_new(0);
	if (!arg)
		return (NULL);
	curr = parts;
	while (curr)
	{
		if (!expand_part(curr->content, arg, ctx))
		{
			ft_string_free(arg);
			return (NULL);
		}
		curr = curr->next;
	}
	return (arg);
}

static int	handle_file_list(t_list *parts, t_array *argv, t_exec_ctx *ctx)
{
	size_t	old_size;
	char	*filter;

	old_size = argv->size;
	filter = expand_filter(parts);
	if (!filter || !expand_files(argv, ctx->env, filter))
	{
		free(filter);
		return (0);
	}
	if (argv->size != old_size)
	{
		free(filter);
		return (1);
	}
	if (!ft_array_push(argv, filter))
	{
		free(filter);
		return (0);
	}
	return (1);
}

int	expand_word(t_list *parts, t_array *argv, t_exec_ctx *ctx)
{
	t_string	*arg;

	if (is_file_list(parts))
		return (handle_file_list(parts, argv, ctx));
	arg = expand_parts(parts, ctx);
	if (!arg)
		return (0);
	if ((arg->size > 1 || has_string(parts)) && !ft_array_push(argv,
			arg->content))
	{
		ft_string_free(arg);
		return (0);
	}
	if (!has_string(parts) && arg->size <= 1)
		ft_string_free(arg);
	else
		free(arg);
	return (1);
}
