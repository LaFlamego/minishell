/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 14:45:06 by Oery              #+#    #+#             */
/*   Updated: 2026/04/26 16:42:46 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./word.h"
#include <stdlib.h>

// TODO: free memory
void	part_free(t_word_part *part)
{
	// if (!part)
	// 	return ;
	// if (part->data)
	// 	free(data);
	free(part);
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

// WARN: verify that free in ft_lstclear is correct
static t_word	*push_part(t_word *word, t_word_kind kind, void *content)
{
	t_word	*next;

	if (!word)
		return (word_from(kind, content));
	next = word_from(kind, content);
	if (!next)
	{
		ft_lstclear(&word, free);
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
