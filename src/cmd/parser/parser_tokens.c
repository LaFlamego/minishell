/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 23:14:30 by Oery              #+#    #+#             */
/*   Updated: 2026/04/02 01:27:04 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"

static void	handle_token(t_parser *p)
{
	p->idx++;
}

// We need to parse a tree
void	parse_tokens(t_parser *p)
{
	t_token	*token;

	token = p->tokens->data[p->idx];
	while (token)
	{
		p->idx++;
		token = p->tokens->data[p->idx];
	}
}
