/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 23:56:01 by Oery              #+#    #+#             */
/*   Updated: 2026/03/23 04:26:14 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell/ctx.h"

static bool	is_valid(const char *key)
{
	return (ft_strchr(key, '=') == NULL);
}

unsigned int	mini_unset(int argc, char *argv[], t_ctx *ctx)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_valid(argv[i]))
			env_unset(ctx->env, argv[i]);
		i++;
	}
	return (0);
}
