/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 16:14:45 by crevette          #+#    #+#             */
/*   Updated: 2026/05/16 21:51:23 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "src/ctx/ctx.h"
#include "src/env/env.h"

// FIXME: var starting with _ are not printed

static void	print_env(t_env *env)
{
	size_t	i;
	char	*kvp;

	i = 0;
	while (i < env->size - 1)
	{
		kvp = env->data[i];
		if (kvp && ft_isalpha(kvp[0]))
			ft_dprintf(1, "%s\n", env->data[i]);
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
