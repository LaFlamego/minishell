/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 12:55:40 by Oery              #+#    #+#             */
/*   Updated: 2026/04/16 14:48:07 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"

// TODO: Add Redirections
static bool	can_start_node(t_token *t)
{
	if (t->type == LEFT_PAREN)
		return (true);
	if (t->type == DOLLAR || t->type == STAR)
		return (true);
	return (false);
}

static t_cmd_node	*parse_node_content(t_parser *p, t_cmd_node *node)
{
	t_token	*token;

	token = parser_peek(p);
	if (!token)
		return (NULL);
	if (!can_start_node(token))
		return (parser_error(token));
	if (token->type == LEFT_PAREN)
	{
		node->data = parser_parse_group();
		return (node->data);
	}
	if (token->type == DOLLAR || token->type == STAR)
	{
		node->data = parser_parse_command();
		return (node->data);
	}
	return (NULL);
}

t_cmd_node	*parser_parse_node(t_parser *p)
{
	t_cmd_node	*node;

	node = node_new(COMMAND);
	if (!node)
		return (NULL);
	node->data = parse_node_content(p, node);
	if (!node->data)
		return (node_free(node));
	return (node);
}
