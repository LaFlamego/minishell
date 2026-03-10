/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 23:56:01 by Oery              #+#    #+#             */
/*   Updated: 2026/03/10 23:58:56 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stddef.h>

int	mini_unset(int argc, char **argv, t_ctx *ctx)
{
	size_t	i;

	i = 1;
	while (i < argc)
	{
		ft_env_unset(ctx->env, argv[i]);
		i++;
	}
	return (0);
}
