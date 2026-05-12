/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 13:12:47 by Oery              #+#    #+#             */
/*   Updated: 2026/05/12 21:32:52 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./expand.h"
#include <stdint.h>

static int	traverse_pipe(t_cmd_node *node)
{
	t_list	*curr;

	curr = node->data;
	while (curr)
	{
		if (!preprocess_heredocs(curr->content))
			return (0);
		curr = curr->next;
	}
	return (1);
}

static int	traverse_arg(t_word *parts)
{
	t_list		*curr;
	t_word_part	*part;
	t_string	*arg;
	int			fd;

	curr = parts;
	while (curr)
	{
		part = curr->content;
		if (part->kind == WK_REDIRECT_IN_UNTIL)
		{
			arg = ft_string_new(0);
			if (!arg)
				return (0);
			if (!expand_heredoc(part, arg))
			{
				ft_string_free(arg);
				return (0);
			}
			fd = redirect_in_until(arg->content);
			if (fd < 0)
			{
				ft_string_free(arg);
				return (0);
			}
			word_free(part->data);
			part->data = (void *)(intptr_t)fd;
			ft_string_free(arg);
		}
		curr = curr->next;
	}
	return (1);
}

static int	traverse_command(t_list *words)
{
	t_list	*curr;

	curr = words;
	while (curr)
	{
		if (!traverse_arg(curr->content))
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	preprocess_heredocs(t_cmd_node *node)
{
	t_bin_op_args	*args;

	if (node->kind == PIPELINE)
	{
		return (traverse_pipe(node));
	}
	if (node->kind == COMMAND)
	{
		return (traverse_command(node->data));
	}
	if (node->kind == OP_AND || node->kind == OP_OR)
	{
		args = node->data;
		if (!preprocess_heredocs(args->left))
			return (0);
		if (!preprocess_heredocs(args->right))
			return (0);
	}
	return (1);
}
