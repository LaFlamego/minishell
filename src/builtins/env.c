/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 16:14:45 by crevette          #+#    #+#             */
/*   Updated: 2026/03/12 14:57:29 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// *DONE env 
// TODO env NAME=val NAME=val ... NAME=val
// TODO env NAME=val NAME=val command(with multiple args it should have)
// TODO error msg - use perror

#include "minishell.h"
#include <stdbool.h>

void	store_keypair(t_ctx *ctx, char *var);
void	env_vars_list(t_ctx *ctx);

t_env *local;

local = ft_env_new();

size_t i;
char  *key;
char  *value;

i = 0;
while (i < ctx->env->size - 1)
{
  key = ctx->env->data[i];
  if (!ft_env_find(local, key))
  {
    value = ft_strchr(key, '=');
    if (value)
      ft_env_set(local, key, value);
  }
  i++;
}

static bool all_vars(char **argv)
{
	while (*argv)
	{
		if (ft_strchr(*argv, '='))
			return (false);
		++argv;
	}
	return (true);
}

static	bool existed_in_env(char *var, t_ctx *ctx)
{

}

static void	run_cmd(char **cmds, t_ctx *ctx)
{
	
}

void	mini_env(int argc, char **argv, t_ctx *ctx)
{
	size_t	i;

	i = 0;
	if (argc == 1)
		vars_list(ctx);
	else if (argc > 1)
	{
		if (all_vars)
			vars_list(ctx);
		++i;
		while (argv[i] && ft_strchr(argv[i], '='))
		{
			if (!existed_in_env(argv[i], ctx))
			{
				store_keypair(ctx, argv[i]);
				if (all_vars)
					printf("%s\n", argv[i]);
			}
			++i;
		}
		if (argv[i])
			run_cmd((argv + i), ctx);
	}
}
