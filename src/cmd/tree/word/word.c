/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 14:45:06 by Oery              #+#    #+#             */
/*   Updated: 2026/04/29 01:55:29 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./word.h"
#include <stdlib.h>

/*
 * part_free() - free a `t_word_part`
 *
 * doesn't free WK_STRING's content as it's owned by the `t_token`
 */
void	part_free(void *raw_part)
{
	t_word_part	*part;

	if (!raw_part)
		return ;
	part = raw_part;
	if (!part->data)
	{
		free(part);
		return ;
	}
	if (part->kind == WK_STRING || part->kind == WK_VARIABLE)
	{
		// free(part->data);
	}
	if (part->kind == WK_REDIRECT_IN || part->kind == WK_REDIRECT_IN_UNTIL)
		part_free(part->data);
	if (part->kind == WK_REDIRECT_OUT || part->kind == WK_REDIRECT_OUT_APPEND)
		part_free(part->data);
	free(part);
}

void	word_free(void *raw_word)
{
	t_word	*word;

	word = raw_word;
	ft_lstclear((t_list **)&word, &part_free);
}

t_word_part	*part_new(t_word_kind kind, void *content)
{
	t_word_part	*part;

	part = ft_calloc(1, sizeof(t_word_part));
	if (!part)
		return (NULL);
	part->kind = kind;
	part->data = content;
	return (part);
}

t_word	*word_from(t_word_kind kind, void *content)
{
	t_word		*word;
	t_word_part	*part;

	word = ft_calloc(1, sizeof(t_word));
	if (!word)
		return (NULL);
	part = ft_calloc(1, sizeof(t_word_part));
	if (!part)
	{
		free(word);
		return (NULL);
	}
	part->kind = kind;
	part->data = content;
	word->content = part;
	return (word);
}

static t_word	*push_part(t_word *word, t_word_kind kind, void *content)
{
	t_word	*next;

	if (!word)
		return (word_from(kind, content));
	next = word_from(kind, content);
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
	return (parser_match(p, STRING) || parser_match(p, DOLLAR));
}

// TODO: A single '$' should turn into a word
// > if there is nothing after
t_word	*parser_parse_string(t_parser *p)
{
	t_word	*word;
	t_token	*t;

	word = NULL;
	while (!parser_match(p, BLANK) && parser_match_word(p))
	{
		t = p->previous->content;
		if (t->type == STRING)
		{
			word = push_part(word, WK_STRING, t->text);
			if (!word)
				return (NULL);
		}
		if (t->type == DOLLAR)
		{
			if (parser_match(p, DOLLAR) || !p->current->next)
			{
				word = push_part(word, WK_STRING, "$");
				continue ;
			}
			else if (!parser_match(p, STRING))
				continue ;
			t = p->previous->content;
			word = push_part(word, WK_VARIABLE, t->text);
		}
	}
	return (word);
}
