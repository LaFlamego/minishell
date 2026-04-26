/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 14:16:13 by Oery              #+#    #+#             */
/*   Updated: 2026/04/26 16:43:46 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORD_H
# define WORD_H

# include "libft.h"
# include "src/parser/parser.h"

/**
 * typedef t_word - a list of parts making up a word.
 *
 * each part is of type `t_word_node *`
 */
typedef t_list	t_word;

/**
 * enum e_word_kind - kind of a word part
 * @WK_STRING: a string - char *
 * @WK_VARIABLE: an environment variable
 * @WK_FILES: a list of files in the current directory
 * @WK_REDIRECT_IN: a redirection
 * @WK_REDIRECT_IN_UNTIL: a redirection
 * @WK_REDIRECT_OUT: a redirection
 * @WK_REDIRECT_OUT_APPEND: a redirection
 */
typedef enum e_word_kind
{
	WK_STRING,
	WK_VARIABLE,
	WK_FILES,
	WK_REDIRECT_IN,
	WK_REDIRECT_IN_UNTIL,
	WK_REDIRECT_OUT,
	WK_REDIRECT_OUT_APPEND,
}				t_word_kind;

/**
 * struct s_word_part - a part of a word
 * @kind: the kind of the node
 * @data: associated data, depends on the @kind field
 *
 * associated data can be of the following:
 * @WK_STRING: `char *`
 * @WK_VARIABLE: `char *`
 * @WK_FILES: `none`
 * @WK_REDIRECT_IN: 't_word'
 * @WK_REDIRECT_IN_UNTIL: a redirection
 * @WK_REDIRECT_OUT: a redirection
 * @WK_REDIRECT_OUT_APPEND: a redirection
 */
typedef struct s_word_part
{
	t_word_kind	kind;
	void		*data;
}				t_word_part;

/**
 * part_new() - create a new `t_word_part`
 * @kind - value of `t_word_part` kind field
 * @content - value of `t_word_part` data field
 */
t_word_part		*part_new(t_word_kind kind, void *content);

/**
 * word_from() - create a new `t_word_part` and wrap it in a `t_word`
 * @kind - kind of `t_word_part`
 * @content - data field for `t_word_part`
 */
t_word			*word_from(t_word_kind kind, void *content);

/**
 * parser_parse_string() - parse a single `t_word`
 * @parser - instance of a `t_parser`
 */
t_word			*parser_parse_string(t_parser *parser);

#endif
