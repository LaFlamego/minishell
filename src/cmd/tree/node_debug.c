/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_debug.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 11:43:15 by Oery              #+#    #+#             */
/*   Updated: 2026/04/26 18:31:13 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./node.h"
#include "./word/word.h"

static void	indent(size_t lvl)
{
	size_t	i;

	i = 0;
	while (i < lvl)
	{
		ft_printf("    ");
		i++;
	}
}

void		debug_words(t_word *parts, size_t depth);
void		debug_part(t_word_part *part, size_t depth);

static void	debug_redirect(t_word_part *node, size_t depth)
{
	indent(depth);
	ft_printf("> REDIRECT [%d]\n", node->kind);
	indent(depth);
	ft_printf("== Value:\n");
	debug_part(node->data, depth + 1);
}

void	debug_part(t_word_part *part, size_t depth)
{
	if (part->kind == WK_STRING)
	{
		indent(depth);
		ft_printf("> STRING\n");
		indent(depth);
		ft_printf("== Value: %s\n", part->data);
	}
	if (part->kind == WK_VARIABLE)
	{
		indent(depth);
		ft_printf("> VARIABLE\n");
		indent(depth);
		ft_printf("== Value: %s\n", part->data);
	}
	if (part->kind == WK_FILES)
	{
		indent(depth);
		ft_printf("> FILES\n");
	}
	if (part->kind >= WK_REDIRECT_IN && part->kind <= WK_REDIRECT_OUT_APPEND)
		debug_redirect(part, depth);
}

void	debug_words(t_word *parts, size_t depth)
{
	t_list	*curr;

	indent(depth);
	ft_printf("> WORDS\n");
	curr = parts;
	while (curr)
	{
		debug_part(curr->content, depth + 1);
		curr = curr->next;
	}
}

static void	debug_command(t_list *words, size_t depth)
{
	t_list	*curr;

	if (!words)
		ft_printf("head is NULL\n");
	indent(depth);
	ft_printf("> COMMAND\n");
	curr = words;
	while (curr)
	{
		debug_words(curr->content, depth + 1);
		curr = curr->next;
	}
}

static void	debug_binary_op(t_cmd_node *n, t_bin_op_args *data, size_t depth)
{
	if (n->kind == OP_AND)
	{
		indent(depth);
		ft_printf("> AND\n");
	}
	else
	{
		indent(depth);
		ft_printf("> OR\n");
	}
	indent(depth);
	ft_printf("== LEFT\n");
	node_debug(data->left, depth + 1);
	indent(depth);
	ft_printf("== RIGHT\n");
	node_debug(data->right, depth + 1);
}

static void	debug_pipeline(t_list *commands, size_t depth)
{
	t_list	*curr;

	indent(depth);
	ft_printf("> PIPELINE\n");
	curr = commands;
	while (curr)
	{
		node_debug(curr->content, depth + 1);
		curr = curr->next;
	}
}

void	node_debug(t_cmd_node *n, size_t depth)
{
	if (!n)
	{
		indent(depth);
		ft_printf("> (null)\n");
		return ;
	}
	if (n->kind == COMMAND)
		debug_command(n->data, depth);
	if (n->kind == PIPELINE)
		debug_pipeline(n->data, depth);
	if (n->kind == OP_AND || n->kind == OP_OR)
		debug_binary_op(n, n->data, depth);
}
