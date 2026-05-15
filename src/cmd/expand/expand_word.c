/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 16:09:55 by Oery              #+#    #+#             */
/*   Updated: 2026/05/15 16:27:00 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./expand.h"
#include "./src/cmd/exec/exec.h"
#include "./src/cmd/tree/word/word.h"
#include <stdlib.h>

int	expand_part(t_word_part *part, t_string *arg, t_array *argv,
		t_exec_ctx *ctx)
{
	if (part->kind == WK_STRING && !ft_string_push_str(arg, part->data))
		return (0);
	if (part->kind == WK_FILES && !expand_files(argv, ctx->env))
		return (0);
	if (part->kind == WK_VARIABLE && !expand_variable(arg, part->data,
			ctx->env))
		return (0);
	if (part->kind >= WK_REDIRECT_IN && part->kind <= WK_REDIRECT_OUT_APPEND)
		return (expand_redirection(part, ctx));
	return (1);
}

static t_string	*expand_parts(t_list *parts, t_array *argv, t_exec_ctx *ctx)
{
	t_list		*curr;
	t_string	*arg;

	arg = ft_string_new(0);
	if (!arg)
		return (NULL);
	curr = parts;
	while (curr)
	{
		if (!expand_part(curr->content, arg, argv, ctx))
		{
			ft_string_free(arg);
			return (NULL);
		}
		curr = curr->next;
	}
	return (arg);
}

int	expand_word(t_list *parts, t_array *argv, t_exec_ctx *ctx)
{
	t_string	*arg;

	arg = expand_parts(parts, argv, ctx);
	if (!arg)
		return (0);
	if (arg->size > 1 && !ft_array_push(argv, arg->content))
	{
		ft_string_free(arg);
		return (0);
	}
	if (arg->size <= 1)
		ft_string_free(arg);
	else
		free(arg);
	return (1);
}
