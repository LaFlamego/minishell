/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 19:03:17 by Oery              #+#    #+#             */
/*   Updated: 2026/04/25 20:37:21 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
# define NODE_H

# include "libft.h"

enum			e_kind
{
	COMMAND,
	PIPELINE,
	OP_AND,
	OP_OR,
	OP_REDIRECT_IN,
	OP_REDIRECT_IN_UNTIL,
	OP_REDIRECT_OUT,
	OP_REDIRECT_OUT_APPEND,
};

/*
 * A tree representing the command to execute
 *
 * The type of the data field depends on the kind of the node:
 * COMMAND -> An array of arrays, each is a word containing a list of tokens.
 * PIPELINE -> An array of t_cmd_node to execute.
 * OP_AND / OP_OR -> t_bin_op_args
 */
typedef struct s_cmd_node
{
	enum e_kind	kind;
	void		*data;
}				t_cmd_node;

typedef struct s_bin_op_args
{
	t_cmd_node	*left;
	t_cmd_node	*right;
}				t_bin_op_args;

t_cmd_node		*node_new(enum e_kind kind);
t_cmd_node		*node_new_bin(t_cmd_node *left, enum e_kind op,
					t_cmd_node *right);
t_cmd_node		*node_free(t_cmd_node *node);

void			node_debug(t_cmd_node *n, size_t depth);

#endif
