/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:55:02 by Oery              #+#    #+#             */
/*   Updated: 2026/04/17 11:41:20 by Oery             ###   ########.fr       */
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

t_parser		parser_new(t_array *tokens);
void			*parser_free(t_parser *p);

t_token			*parser_advance(t_parser *p);
t_token			*parser_peek(t_parser *p);
void			*parser_error(t_token *t);

t_cmd_node		*parser_parse_node(t_parser *p);
t_cmd_args		*parser_parse_cmd(t_parser *p);

#endif
