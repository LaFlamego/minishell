/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 16:16:02 by Oery              #+#    #+#             */
/*   Updated: 2026/04/25 18:10:14 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"
#include <stdlib.h>

static void	*push_token(t_list **lst, void *content)
{
	t_list	*node;

	if (!content)
		return (NULL);
	node = ft_lstnew(content);
	if (!node)
		return (NULL);
	ft_lstadd_back(lst, node);
	return (node);
}

// TODO: do we need to clean something on error?
t_cmd_node	*parser_parse_command(t_parser *p)
{
	t_token		*t;
	t_cmd_node	*node;
	t_list		*curr;
	t_list		*new;

	node = node_new(COMMAND);
	if (!node)
		return (NULL);
	curr = NULL;
	while (parser_match_command(p))
	{
		t = p->previous->content;
		// ft_printf("Current Kind = %s\n",
		// token_to_string(p->current->content));
		ft_printf("Previous Kind = %s\n", token_to_string(t));
		if (t->type == BLANK)
		{
			ft_printf("Curr = %p\n", curr);
			if (curr)
			{
				new = ft_lstnew(curr);
				if (!new)
					return (NULL);
				ft_lstadd_back((t_list **)&node->data, new);
			}
			curr = NULL;
		}
		else
		{
			if (!push_token(&curr, t))
				return (NULL);
		}
	}
	if (curr)
	{
		new = ft_lstnew(curr);
		if (!new)
			return (NULL);
		ft_lstadd_back((t_list **)&node->data, new);
	}
	return (node);
}
