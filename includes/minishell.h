/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 16:55:40 by Oery              #+#    #+#             */
/*   Updated: 2026/03/13 18:22:59 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: Fields
// > History
// > Last command exit code
// > Signals?

#ifndef MINISHELL_H
# define MINISHELL_H

# include "minishell/env.h"
// Needed for Readline
# include <stdio.h>

// TODO: Bonus operations
typedef enum e_ops
{
	NONE,
	INSERT_CMD,
	INSERT_ENV_VAR,
	REDIRECT_INPUT,
	REDIRECT_OUTPUT,
	READ_UNTIL,
	REDIRECT_APPEND,
	PIPE,
}					t_ops;

typedef struct s_node
{
	t_ops			op;
	int				done;
	void			*data;
	struct s_node	*left;
	struct s_node	*right;
}					t_node;

typedef struct s_ctx
{
	t_env			*env;
	bool			exit;
}					t_ctx;

void				prompt_display(t_ctx *ctx);


#endif
