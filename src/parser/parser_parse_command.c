/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 16:16:02 by Oery              #+#    #+#             */
/*   Updated: 2026/04/26 17:14:35 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"
#include "src/cmd/tree/word/word.h"
#include <stdlib.h>

enum e_kind			token_tokind(t_token *t);

static void	*push_word(void *lst_raw, void *content)
{
	t_list	**lst;
	t_list	*node;

	lst = lst_raw;
	if (!content)
		return (NULL);
	node = ft_lstnew(content);
	if (!node)
		return (NULL);
	ft_lstadd_back(lst, node);
	return (node);
}

static t_cmd_node	*push_to_word(t_cmd_node *word, char *text)
{
	if (!word)
		return (node_new_string(text));
	if (!ft_string_push_str(word->data, text))
		return (node_free(word));
	return (word);
}

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

// TODO: Parse one word
// 1. A word can be:
// 	- a variable
// 	- a string
// 	- a double quoted string
// 	- a redirection
// 	- a wildcard x

static t_word	*parse_word(t_parser *p)
{
	t_word		*word;
	t_token		*op;
	t_token		*t;
	t_word_part	*inner;

	if (parser_match(p, STAR))
		return (word_from(WK_FILES, NULL));
	if (parser_match_redirection(p))
	{
		op = p->previous->content;
		if (parser_match(p, STRING))
		{
			t = p->previous->content;
			inner = part_new(WK_STRING, t->text);
			// TODO: Handle error
			return (word_from(tokind(op->type), inner));
		}
		else if (parser_match(p, DOLLAR))
		{
			// TODO: Should this be a syntax error?
			// > no because a single dollar is a string
			// > needs testing
			if (!parser_match(p, STRING))
				inner = part_new(WK_STRING, "$");
			else
			{
				t = p->previous->content;
				inner = part_new(WK_VARIABLE, t->text);
			}
			// TODO: handle error in inner
			word = word_from(tokind(op->type), inner);
			// TODO: handle error
			return (word);
		}
		else
		{
			parser_error(op);
			// TODO: syntax error
			return (NULL);
		}
	}
	return (parser_parse_string(p));
}

// A command
// > each part is a word
// > each word can be made of multiple strings

/**
 * parser_parse_command() - Parse a command node
 * @p: instance of a `t_parser`
 *
 * A command is a `t_list` where each element is a `t_word`
 */
t_cmd_node	*parser_parse_command(t_parser *p)
{
	t_cmd_node	*node;
	t_word		*word;

	node = node_new(COMMAND);
	if (!node)
		return (NULL);
	while (parser_check_command(p))
	{
		word = parse_word(p);
		if (!word)
			return (node_free(node));
		if (!push_word(&node->data, word))
		{
			ft_lstclear(&word, free);
			return (node_free(node));
		}
	}
	return (node);
}
