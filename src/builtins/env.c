/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 16:14:45 by crevette          #+#    #+#             */
/*   Updated: 2026/05/17 22:53:49 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "src/ctx/ctx.h"
#include "src/env/env.h"

static bool	is_valid_arg(char *arg)
{
	int	i;

	if (!ft_isalpha(arg[0]) && arg[0] != '_')
		return (false);
	i = 1;
	while (arg[i] && arg[i] != '=')
	{
		if (!ft_isalpha(arg[i]) && !ft_isdigit(arg[i]) && arg[i] != '_')
			return (false);
		++i;
	}
	return (true);
}

static void	print_env(t_env *env)
{
	size_t	i;
	char	*kvp;

	i = 0;
	while (i < env->size - 1)
	{
		kvp = env->data[i];
		if (kvp && is_valid_arg(kvp))
			ft_dprintf(1, "%s\n", kvp);
		i++;
	}
}

unsigned int	mini_env(int argc, char *argv[], t_ctx *ctx)
{
	(void)argv;
	if (argc > 1)
	{
		ft_dprintf(2, "minishell: exit: too many arguments\n");
		return (2);
	}
	print_env(ctx->env);
	return (0);
}
