/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 13:12:47 by Oery              #+#    #+#             */
/*   Updated: 2026/05/18 00:41:02 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./expand.h"
#include <stdint.h>

static int	expand_del(t_list *parts, t_string *arg)
{
	t_list		*curr;
	t_word_part	*part;

	curr = parts;
	while (curr)
	{
		part = curr->content;
		if (!expand_heredoc(part, arg))
			return (0);
		curr = curr->next;
	}
	return (1);
}

static int	handle_arg(t_word_part *part, t_env *env)
{
	t_string	*arg;
	int			fd;

	arg = ft_string_new(0);
	if (!arg)
		return (0);
	if (!expand_del(part->data, arg))
	{
		ft_string_free(arg);
		return (0);
	}
	fd = redirect_in_until(arg->content, env);
	if (fd < 0)
	{
		ft_string_free(arg);
		return (0);
	}
	word_free(part->data);
	part->data = (void *)(intptr_t)fd;
	ft_string_free(arg);
	part->kind = WK_REDIRECT_IN_UNTIL_FD;
	return (1);
}

static int	traverse_parts(t_list *parts, t_env *env)
{
	t_word		*curr;
	t_word_part	*part;

	curr = parts;
	while (curr)
	{
		part = curr->content;
		if (part->kind == WK_REDIRECT_IN_UNTIL && !handle_arg(part, env))
		{
			return (0);
		}
		curr = curr->next;
	}
	return (1);
}

static int	traverse_words(t_word *words, t_env *env)
{
	t_word	*curr;
	t_list	*parts;

	curr = words;
	while (curr)
	{
		parts = curr->content;
		if (!traverse_parts(parts, env))
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	preprocess_heredocs(t_cmd_node *node, t_env *env)
{
	if (node->kind == COMMAND)
	{
		return (traverse_words(node->data, env));
	}
	return (1);
}
