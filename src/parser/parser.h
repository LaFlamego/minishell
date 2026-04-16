/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:55:02 by Oery              #+#    #+#             */
/*   Updated: 2026/04/16 12:29:26 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "src/cmd/tree/node.h"
# include "src/scanner/token/token.h"

typedef struct s_parser
{
	t_array		*tokens;
	size_t		current;
	t_cmd_node	*tree;
}				t_parser;

t_token			*parser_advance(t_parser *p);
t_token			*parser_peek(t_parser *p);

#endif
