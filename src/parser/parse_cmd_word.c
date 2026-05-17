/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 22:28:27 by Oery              #+#    #+#             */
/*   Updated: 2026/05/17 02:53:55 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"

static t_word	*push_part(t_word *word, t_word_part *part)
{
	t_word	*next;

	if (!word)
		return (word_from(part));
	next = word_from(part);
	if (!next)
	{
		ft_lstclear(&word, part_free);
		return (NULL);
	}
	ft_lstadd_back(&word, next);
	return (word);
}

static bool	parser_match_word(t_parser *p)
{
	if (parser_check(p, BLANK))
		return (false);
	if (parser_match(p, STAR))
		return (true);
	return (parser_match(p, STRING) || parser_match(p, DOLLAR));
}

static t_word_part	*parse_part(t_parser *p)
{
	t_token	*t;

	t = p->previous->content;
	if (t->type == STAR)
		return (part_new(WK_FILES, NULL));
	if (t->type == STRING)
		return (part_new(WK_STRING, t->text));
	if (t->type == DOLLAR)
		return (parser_parse_variable(p));
	return (NULL);
}

t_word	*parser_parse_cmd_word(t_parser *p)
{
	t_word		*word;
	t_word_part	*part;

	word = NULL;
	while (parser_match_word(p))
	{
		part = parse_part(p);
		if (!part)
		{
			word_free(word);
			return (NULL);
		}
		word = push_part(word, part);
		if (!word)
			return (NULL);
	}
	return (word);
}
