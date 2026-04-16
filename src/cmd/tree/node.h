/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 19:03:17 by Oery              #+#    #+#             */
/*   Updated: 2026/04/16 14:28:29 by Oery             ###   ########.fr       */
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
};

typedef struct s_cmd_node
{
	enum e_kind	kind;
	void		*data;
}				t_cmd_node;

typedef struct s_pipe_args
{
	t_array		*commands;
}				t_pipe_args;

typedef struct s_cmd_args
{
	t_array		*args;
}				t_cmd_args;

typedef struct s_bin_op_args
{
	t_cmd_node	*left;
	t_cmd_node	*right;
}				t_bin_op_args;

t_cmd_node		*node_new(enum e_kind kind);
t_cmd_node		*node_free(t_cmd_node *node);

#endif
