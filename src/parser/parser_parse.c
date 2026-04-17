/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 19:01:14 by Oery              #+#    #+#             */
/*   Updated: 2026/04/17 12:08:16 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"
#include "libft.h"
#include "src/scanner/token/token.h"

t_token	*parser_advance(t_parser *p)
{
	p->current++;
	if (!p->tokens)
		return (NULL);
	if (p->current >= p->tokens->size)
		return (NULL);
	return (p->tokens->data[p->current - 1]);
}

t_token	*parser_peek(t_parser *p)
{
	if (!p->tokens)
		return (NULL);
	if (p->current >= p->tokens->size)
		return (NULL);
	return (p->tokens->data[p->current]);
}
