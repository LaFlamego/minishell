/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:55:02 by Oery              #+#    #+#             */
/*   Updated: 2026/05/08 19:52:25 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "src/cmd/tree/node.h"
# include "src/cmd/tree/word/word.h"
# include "src/scanner/token/token.h"

typedef struct s_parser
{
	t_list		*tokens;
	t_list		*current;
	t_list		*previous;
	t_cmd_node	*tree;
}				t_parser;

t_parser		parser_new(t_list *tokens);
void			*parser_free(t_parser *p);

t_token			*parser_advance(t_parser *p);
t_token			*parser_peek(t_parser *p);
void			*parser_error(t_parser *p, t_token *t);

bool			parser_check(t_parser *p, t_token_type type);
bool			parser_match(t_parser *p, t_token_type type);
bool			parser_match_binary(t_parser *p);
bool			parser_match_command(t_parser *p);
bool			parser_match_redirection(t_parser *p);

bool			parser_check_command(t_parser *p);

t_cmd_node		*parser_parse(t_parser *p);
t_cmd_node		*parser_parse_pipe(t_parser *p);

/**
 * parser_parse_binary() - try to parse a binary operation
 * @p: pointer to a t_parser
 *
 * If no operator is found, returns the left side of the operation.
 *
 * Return:
 * On success, a pointer to a command node (must be freed)
 * On error, a NULL pointer
 */
t_cmd_node		*parser_parse_binary(t_parser *p);
t_cmd_node		*parser_parse_command(t_parser *p);
t_cmd_node		*parser_parse_primary(t_parser *p);

/**
 * parser_parse_string() - parse a single `t_word`
 * @parser - instance of a `t_parser`
 */
t_word			*parser_parse_string(t_parser *parser);

// TODO: docs
t_word_part		*parser_parse_variable(t_parser *parser);

t_word			*parser_parse_cmd_arg(t_parser *p);
t_word			*parser_parse_cmd_word(t_parser *p);

enum e_kind		token_to_kind(t_token *token);

#endif
