/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 23:56:01 by Oery              #+#    #+#             */
/*   Updated: 2026/03/12 19:16:18 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdbool.h>

static bool	is_valid(const char *key)
{
	return (ft_strchr(key, '=') == NULL);
}

int	mini_unset(int argc, char **argv, t_ctx *ctx)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_valid(argv[i]))
			ft_env_unset(ctx->env, argv[i]);
		i++;
	}
	return (0);
}
