/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 19:01:14 by Oery              #+#    #+#             */
/*   Updated: 2026/04/15 16:19:14 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"
#include "libft.h"
#include "src/cmd/cmd.h"
#include "src/scanner/token/token.h"

// TODO: Default case should try to determine an operation
// > So either a command or an operation
t_cmd_node	*parse_token(t_parser *p)
{
	t_token	*t;

	t = parser_advance(p);
	if (!t)
		return (NULL);
}

t_token	*parser_advance(t_parser *p)
{
	p->current++;
	if (!p->tokens)
		return (NULL);
	if (p->current >= p->tokens->size)
		return (NULL);
	return (p->tokens->data[p->current - 1]);
}

t_token	*parser_peek(t_parser *p)
{
	if (!p->tokens)
		return (NULL);
	if (p->current >= p->tokens->size)
		return (NULL);
	return (p->tokens->data[p->current]);
}

static void	skip_blanks(t_parser *p)
{
	while (parser_peek(p)->type == BLANK)
		p->current++;
}

t_cmd_node	*parser_parse(t_parser *p)
{
	if (!p->tokens)
		return (NULL);
	skip_blanks(p);
	while (p->tokens->data[p->current])
	{
		if (!parse_token(p))
			return (NULL);
	}
	return (p->tree);
}
