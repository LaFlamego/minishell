/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 16:16:02 by Oery              #+#    #+#             */
/*   Updated: 2026/05/04 23:09:15 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"
#include "src/cmd/tree/word/word.h"
#include <stdlib.h>

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
		word = parser_parse_cmd_arg(p);
		if (!word || !push_word(&node->data, word))
		{
			ft_lstclear(&word, word_free);
			return (node_free(node));
		}
	}
	return (node);
}
