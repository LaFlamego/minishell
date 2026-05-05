/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 21:14:13 by Oery              #+#    #+#             */
/*   Updated: 2026/05/05 01:15:31 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"
#include "src/cmd/tree/word/word.h"
#include <stdlib.h>

static t_word_kind	tokind(t_token_type kind)
{
	if (kind == REDIRECT_IN)
		return (WK_REDIRECT_IN);
	if (kind == REDIRECT_IN_UNTIL)
		return (WK_REDIRECT_IN_UNTIL);
	if (kind == REDIRECT_OUT)
		return (WK_REDIRECT_OUT);
	if (kind == REDIRECT_OUT_APPEND)
		return (WK_REDIRECT_OUT_APPEND);
	return (0);
}

t_word	*parser_parse_cmd_arg(t_parser *p)
{
	t_token	*op;
	t_word	*word;

	if (parser_match(p, STAR))
	{
		return (word_from(part_new(WK_FILES, NULL)));
	}
	if (parser_match_redirection(p))
	{
		op = p->previous->content;
		word = parser_parse_cmd_word(p);
		if (!word)
			return (NULL);
		return (word_from(part_new(tokind(op->type), word)));
	}
	return (parser_parse_cmd_word(p));
}
