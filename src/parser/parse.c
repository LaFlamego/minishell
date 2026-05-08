/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 19:01:14 by Oery              #+#    #+#             */
/*   Updated: 2026/05/08 20:10:03 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"
#include "libft.h"
#include "src/scanner/token/token.h"

t_token	*parser_advance(t_parser *p)
{
	if (!p->current)
		return (NULL);
	p->previous = p->current;
	p->current = p->current->next;
	return (p->current->content);
}

t_token	*parser_peek(t_parser *p)
{
	if (!p->current)
		return (NULL);
	return (p->current->content);
}

bool	parser_check(t_parser *p, t_token_type type)
{
	t_token	*token;

	token = parser_peek(p);
	if (!token)
		return (NULL);
	return (token->type == type);
}

t_cmd_node	*parser_parse(t_parser *p)
{
	t_cmd_node	*head;

	head = parser_parse_binary(p);
	if (!parser_check(p, EOF))
	{
		parser_error(p, parser_peek(p));
		node_free(head);
		return (NULL);
	}
	p->tree = head;
	return (p->tree);
}
