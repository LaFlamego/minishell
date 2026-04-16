/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 20:44:38 by Oery              #+#    #+#             */
/*   Updated: 2026/04/16 15:12:51 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"
#include "src/cmd/tree/node.h"
#include <stdlib.h>

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

// TODO:
static int	handle_token(t_parser *p, t_cmd_args *cmd, t_token *t)
{
	t_array	*word;

	if (t->type == BLANK)
		return (0);
	word = parse_word(p, t);
	if (!word)
		return (1);
	if (!ft_array_push(&cmd->args, word))
	{
		free(word);
		return (1);
	}
	return (0);
}

// NOTE: Steps
// > Create the args struct
// > Read Tokens until either EOF or operation token
// > For now, each word is just an array of strings/dollar

// TODO: Should validation be here as well?
t_cmd_args	*parser_parse_cmd(t_parser *p)
{
	t_token		*token;
	t_cmd_args	*cmd;

	token = parser_peek(p);
	while (token && is_command(token))
	{
		if (!handle_token(p, cmd, token))
			return (NULL);
		parser_advance(p);
		token = parser_peek(p);
	}
	return (cmd);
}
