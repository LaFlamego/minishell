/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 17:13:23 by Oery              #+#    #+#             */
/*   Updated: 2026/05/03 17:36:23 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "src/cmd/tree/node.h"
# include "src/cmd/tree/word/word.h"

void	debug_argv(t_array *argv);

void	debug_indent(size_t lvl);

void	debug_node(t_cmd_node *n, size_t depth);

void	debug_node_redirect(t_word_part *node, size_t depth);

void	debug_node_string(t_word_part *part, size_t depth, char *text);

void	debug_token_list(t_list *tokens);

void	debug_words(t_word *parts, size_t depth);

void	debug_part(t_word_part *part, size_t depth);

#endif
