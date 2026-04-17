/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 20:44:38 by Oery              #+#    #+#             */
/*   Updated: 2026/04/17 12:38:12 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"
#include "src/cmd/tree/node.h"
#include <stdlib.h>

// TODO: Redirections support
// > Redirections must all be applied once even if overridden
// > Ex: echo test >a >b will still nuke file a content

static bool	is_command(t_token_type t)
{
	if (t == STRING || t == DOLLAR || t == BLANK)
		return (true);
	if (t == REDIRECT_IN || t == REDIRECT_IN_UNTIL)
		return (true);
	if (t == REDIRECT_OUT || t == REDIRECT_OUT_APPEND)
		return (true);
	return (false);
}

// TODO: Handle push errors
static t_array	*parse_word(t_parser *p, t_cmd_args *cmd, t_token *t)
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
	ft_array_push(&cmd->args, word);
	return (word);
}

// TODO: Redirections support
// TODO: Dollarsign support
static void	*handle_token(t_parser *p, t_cmd_args *cmd, t_token *t)
{
	if (t->type == BLANK)
		return (p);
	if (t->type == STRING || t->type == DOLLAR)
		return (parse_word(p, cmd, t));
	// if (token_is_redirect(t))
	// 	return (parse_redirection(p, cmd, t));
	return (NULL);
}

// NOTE: Steps
// > Create the args struct
// > Read Tokens until either EOF or operation token
// > For now, each word is just an array of strings/dollar

// TODO: Replace the void* with an union
t_cmd_args	*parser_parse_cmd(t_parser *p)
{
	t_token		*token;
	t_cmd_args	*cmd;

	token = parser_peek(p);
	cmd = ft_calloc(sizeof(t_cmd_args), 1);
	if (!cmd)
		return (NULL);
	while (token && is_command(token->type))
	{
		if (!handle_token(p, cmd, token))
			return (NULL);
		parser_advance(p);
		token = parser_peek(p);
	}
	return (cmd);
}
