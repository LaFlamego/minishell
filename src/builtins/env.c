/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 16:14:45 by crevette          #+#    #+#             */
/*   Updated: 2026/03/12 16:16:24 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// *DONE env 
// *DONE env NAME=val NAME=val ... NAME=val
// *DONE env NAME=val NAME=val command(with multiple args it should have)
// TODO error msg - use perror

#include "minishell.h"
#include <stdbool.h>

void	env_vars_list(t_ctx *ctx);

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

void	get_path(char **cmds)
{

}

static void	run_cmd(char **cmds, t_ctx *ctx)
{
	
}

void	mini_env(int argc, char **argv, t_ctx *ctx)
{
	size_t	i;
	t_env	*local;

	local = ft_env_new();
	if (!local)
		return ;
	if (argc == 1)
		vars_list(ctx);
	else if (argc > 1)
	{
		i = 1;
		if (all_vars)
			vars_list(ctx);
		while (argv[i] && ft_strchr(argv[i], '='))
		{
			ft_env_set(local, argv[i]);
			if (all_vars)
				printf("%s\n", argv[i]);
			++i;
		}
		ft_env_merge(local, ctx->env);
		if (argv[i])
			run_cmd((argv + i), ctx);
	}
}
