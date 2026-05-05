/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 22:28:27 by Oery              #+#    #+#             */
/*   Updated: 2026/05/05 20:07:49 by Oery             ###   ########.fr       */
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
	return (parser_match(p, STRING) || parser_match(p, DOLLAR));
}

// TODO: maybe pass a ref to the t_word var instead of returning it
// then we could directly do if (!push_part(&word))

// FIXME: Watch out for error handling, word should be freed probably
t_word	*parser_parse_cmd_word(t_parser *p)
{
	t_token		*t;
	t_word		*word;
	t_word_part	*part;

	word = NULL;
	while (parser_match_word(p))
	{
		part = NULL;
		t = p->previous->content;
		if (t->type == STRING)
		{
			part = part_new(WK_STRING, t->text);
		}
		if (t->type == DOLLAR)
		{
			part = parser_parse_variable(p);
		}
		if (!part)
			return (NULL);
		word = push_part(word, part);
		if (!word)
			return (NULL);
	}
	return (word);
}
