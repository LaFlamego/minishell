/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 16:16:02 by Oery              #+#    #+#             */
/*   Updated: 2026/04/25 17:18:10 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"
#include <stdlib.h>

static void	*push_token(void *data, t_token *new)
{
	t_list	**lst;
	t_list	*node;

	lst = data;
	if (!new)
		return (NULL);
	node = ft_lstnew(new);
	if (!node)
		return (NULL);
	ft_lstadd_back(lst, node);
	return (node);
}

t_cmd_node	*parser_parse_command(t_parser *p)
{
	t_token		*t;
	t_cmd_node	*node;

	node = node_new(COMMAND);
	if (!node)
		return (NULL);
	if (!push_token(&node->data, p->previous->content))
	{
		node_free(node);
		return (NULL);
	}
	while (parser_match_command(p))
	{
		t = p->previous->content;
		if (t->type != BLANK && !push_token(&node->data, t))
		{
			node_free(node);
			return (NULL);
		}
	}
	return (node);
}
