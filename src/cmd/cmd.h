/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:50:13 by Oery              #+#    #+#             */
/*   Updated: 2026/04/15 17:55:22 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include "libft.h"
# include "src/ctx/ctx.h"

// TODO: Add bonuses
// typedef enum s_kind
// {
// 	STRING,
// 	INSERT_CMD,
// 	INSERT_ENV_VAR,
// 	REDIRECT_INPUT,
// 	REDIRECT_OUTPUT,
// 	READ_UNTIL,
// 	REDIRECT_APPEND,
// 	PIPE,
// }				t_kind;

enum				e_kind
{
	COMMAND,
};

typedef struct s_op
{
	struct s_node	*left;
	struct s_node	*right;
}					t_op;

typedef struct s_node
{
	enum e_kind		kind;
	union
	{
		t_op		op;
		t_array		*tokens;
	};
}					t_node;

typedef struct s_cmd
{
	char			*path;
	char			**cmds;
	int				nb;
	bool			valid;
	bool			f_no_x;
	bool			is_path;
}					t_cmd;

bool				is_sq_string(t_string *s);
unsigned int		cmd_handle(const char *input, t_ctx *ctx);
void				cmd_quotes_remove(const t_array *words);

#endif
