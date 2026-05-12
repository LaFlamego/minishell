/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 13:12:47 by Oery              #+#    #+#             */
/*   Updated: 2026/05/12 13:34:38 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./expand.h"
#include <stdint.h>

static void	traverse_pipe(t_cmd_node *node)
{
	t_list	*curr;

	curr = node->data;
	while (curr)
	{
		preprocess_heredocs(curr->content);
		curr = curr->next;
	}
}

// TODO: Make sure t_string does not leak
// FIXME: handle errors
// > pretty much everything can fail
static void	traverse_arg(t_word *parts)
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
			expand_heredoc(part, arg);
			fd = redirect_in_until(arg);
			if (fd < 0)
			{
				// FIXME: handle error
			}
			word_free(part->data);
			part->data = (void *)(intptr_t)fd;
			ft_string_free(arg);
		}
		curr = curr->next;
	}
}

static void	traverse_command(t_list *words)
{
	t_list	*curr;

	curr = words;
	while (curr)
	{
		traverse_arg(curr->content);
		curr = curr->next;
	}
}

void	preprocess_heredocs(t_cmd_node *node)
{
	t_bin_op_args	*args;

	if (node->kind == PIPELINE)
	{
		traverse_pipe(node);
	}
	if (node->kind == COMMAND)
	{
		traverse_command(node->data);
	}
	if (node->kind == OP_AND || node->kind == OP_OR)
	{
		args = node->data;
		preprocess_heredocs(args->left);
		preprocess_heredocs(args->right);
	}
}
