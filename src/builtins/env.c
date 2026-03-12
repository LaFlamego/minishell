/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 16:14:45 by crevette          #+#    #+#             */
/*   Updated: 2026/03/13 00:08:00 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

// TODO: $? should not printed?
static void	print_env(t_env *env)
{
	size_t	i;

	i = 0;
	while (i < env->size - 1)
	{
		ft_dprintf(0, "%s\n", env->data[i]);
		i++;
	}
}

unsigned int	mini_env(int argc, char **argv, t_ctx *ctx)
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
