/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 16:29:31 by Oery              #+#    #+#             */
/*   Updated: 2026/04/10 18:25:31 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"
#include "src/cmd/cmd.h"
#include <stdlib.h>

// WARN: Print Syntax Error ?
// > Pass error code as argument?
static int	error(t_parser *p)
{
	free((void *)p->lex.input);
	return (1);
}

// NOTE: There cannot be 3 pipes in a row

// NOTE: First token should be part of a classic command?
// > Keep Adding to the command
//
// How should we represent something"$VAR"
// so commands should still be stored as token streams until expansion?
// or maybe as strings?

// should constantly push new words to last command.args
int	parse_command(t_parser *p)
{
	t_node	*curr;

	p->tree = malloc(sizeof(t_node));
	if (!p->tree)
		return (1);
	curr = p->tree;
	// create a new head with a command
	// parse that command
	if (lexer_advance(&p->lex))
		return (error(p));
	while (p->lex.next_token)
	{
		// add that token to the current command
		ft_array_push(curr->tokens, p->lex.next_token);
		if (lexer_advance(&p->lex))
			return (error(p));
	}
	return (0);
}
