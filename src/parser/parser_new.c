/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:56:53 by Oery              #+#    #+#             */
/*   Updated: 2026/04/17 12:21:30 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"
#include "libft.h"
#include <stdlib.h>

t_parser	parser_new(t_array *tokens)
{
	t_parser	p;

	ft_bzero(&p, sizeof(t_parser));
	p.tokens = tokens;
	return (p);
}

void	*parser_free(t_parser *p)
{
	if (!p)
		return (NULL);
	if (p->tokens)
		ft_array_free(p->tokens, free);
	node_free(p->tree);
	return (NULL);
}
