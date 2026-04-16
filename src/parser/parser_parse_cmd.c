/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 20:44:38 by Oery              #+#    #+#             */
/*   Updated: 2026/04/16 12:38:56 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"
#include "src/cmd/tree/node.h"

// TODO: Space flag?
// > $ should be part of the same word

static bool	is_command(t_token *t)
{
	return (t->type == STRING || t->type == BLANK);
}

static t_array	*parse_word(t_parser *p, t_token *t)
{
	t_array	*word;

	word = ft_array_new();
	if (!word)
		return (NULL);
	t = parser_peek(p);
	while (t && (t->type == STRING || t->type == DOLLAR))
	{
		ft_array_push(word, t);
		parser_advance(p);
		t = parser_peek(p);
	}
	// TODO: Add somewhere
	return (word);
}

static int	parse_blank(t_parser *p)
{
	t_token	*t;

	t = parser_peek(p);
	while (t && t->type == BLANK)
	{
		parser_advance(p);
		t = parser_peek(p);
	}
	return (0);
}

static int	handle_token(t_parser *p, t_cmd_node *node, t_token *t)
{
	t_array	*word;

	if (t->type == BLANK)
	{
		parse_blank(p);
	}
	else
	{
		word = parse_word(p, t);
		if (!word)
			return (1);
		if (!ft_array_push(node->data, word))
			return (1);
	}
	return (0);
}

t_cmd_node	*op_parse_cmd(t_parser *p)
{
	t_token		*token;
	t_cmd_node	*node;

	node = node_new(COMMAND);
	if (!node)
		return (NULL);
	token = parser_peek(p);
	while (token && is_command(token))
	{
		if (!handle_token(p, node, token))
			return (NULL);
		parser_advance(p);
		token = parser_peek(p);
	}
	return (node);
}
