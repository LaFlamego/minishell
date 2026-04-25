/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 19:01:14 by Oery              #+#    #+#             */
/*   Updated: 2026/04/25 17:17:13 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"
#include "libft.h"
#include "src/scanner/token/token.h"

t_token	*parser_advance(t_parser *p)
{
	if (!p->current->next)
		return (NULL);
	p->previous = p->current;
	p->current = p->current->next;
	return (p->current->content);
}

t_token	*parser_peek(t_parser *p)
{
	if (!p->current->next)
		return (NULL);
	return (p->current->next->content);
}

// t_token	*parser_previous(t_parser *p)
// {
// 	if (p->current == 0)
// 		return (NULL);
// 	if (p->current - 1 >= p->tokens->size)
// 		return (NULL);
// 	return (p->tokens->data[p->current - 1]);
// }

bool	parser_check(t_parser *p, t_token_type type)
{
	t_token	*token;

	if (!p->current || !p->current->next)
		return (false);
	token = parser_peek(p);
	if (!token)
		return (NULL);
	return (token->type == type);
}

// TODO: Clean parser on error here
t_cmd_node	*parser_parse(t_parser *p)
{
	t_cmd_node	*head;

	head = parser_parse_expr(p);
	p->tree = head;
	return (p->tree);
}
