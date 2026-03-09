/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 16:55:40 by Oery              #+#    #+#             */
/*   Updated: 2026/03/09 21:15:04 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: Fields
// > History
// > Last command exit code
// > Signals?

#ifndef MINISHELL_H
# define MINISHELL_H

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
	char			**env;
}					t_ctx;

void	prompt_display(void);

#endif
