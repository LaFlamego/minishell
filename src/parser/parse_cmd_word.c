/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 22:28:27 by Oery              #+#    #+#             */
/*   Updated: 2026/05/08 20:08:52 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"

static bool	has_wildcard(t_word *word)
{
	t_word_part	*part;
	t_word		*curr;

	curr = word;
	while (curr)
	{
		part = curr->content;
		if (part->kind == WK_FILES)
			return (true);
		curr = curr->next;
	}
	return (false);
}

// FIXME: Make sure a word does not have a wildcard?

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
		if (has_wildcard(word) || (word && t->type == STAR))
		{
			parser_error(p, t);
			word_free(word);
			return (NULL);
		}
		if (t->type == STAR)
		{
			part = part_new(WK_FILES, NULL);
		}
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
