/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 21:14:13 by Oery              #+#    #+#             */
/*   Updated: 2026/05/14 14:23:09 by Oery             ###   ########.fr       */
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

static bool	has_wildcard(t_list *parts)
{
	t_list		*curr;
	t_word_part	*part;

	curr = parts;
	while (curr)
	{
		part = curr->content;
		if (part->kind == WK_FILES)
			return (true);
		curr = curr->next;
	}
	return (false);
}

static bool	check_word(t_parser *p)
{
	while (parser_match(p, BLANK))
		;
	if (parser_check(p, BLANK) || parser_check(p, STRING))
		return (true);
	if (parser_check(p, DOLLAR) || parser_check(p, STAR))
		return (true);
	return (false);
}

t_word	*parser_parse_cmd_arg(t_parser *p)
{
	t_token	*op;
	t_word	*word;

	if (parser_match_redirection(p))
	{
		op = p->previous->content;
		if (!check_word(p))
			return (parser_error(p, parser_peek(p)));
		word = parser_parse_cmd_word(p);
		if (!word)
			return (NULL);
		if (op->type != REDIRECT_IN_UNTIL && has_wildcard(word))
		{
			ft_dprintf(2, "minishell: *: ambiguous redirect\n");
			while (p->current && p->current->next)
				p->current = p->current->next;
			word_free(word);
			return (NULL);
		}
		return (word_from(part_new(tokind(op->type), word)));
	}
	while (parser_match(p, BLANK))
		;
	return (parser_parse_cmd_word(p));
}
