/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 16:55:40 by Oery              #+#    #+#             */
/*   Updated: 2026/03/10 23:18:22 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: Fields
// > History
// > Last command exit code
// > Signals?

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
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

typedef t_array		t_env;

t_env				*ft_env_from(char **envp);
t_env				*ft_env_free(t_env *env);
void				*ft_env_get(t_env *env, char *key);
void				ft_env_set(t_env *env, char *key, char *value);
void				ft_env_unset(t_env *env, char *key);

typedef struct s_ctx
{
	t_env			*env;
}					t_ctx;

void				prompt_display(t_ctx *ctx);

// builtins
void				mini_export(int argc, char **argv, t_ctx *ctx);

#endif
