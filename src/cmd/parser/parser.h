/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 16:03:47 by Oery              #+#    #+#             */
/*   Updated: 2026/04/02 01:22:37 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "src/cmd/cmd.h"
# include "src/cmd/lexer/lexer.h"

typedef struct s_parser
{
	t_lexer	lex;
	t_node	*tree;
}			t_parser;

// typedef struct s_raw_cmd
// {
// }			t_raw_cmd;

t_parser	parser_new(const char *input);
int			parse_command(t_parser *p);

#endif
