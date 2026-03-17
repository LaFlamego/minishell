/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:40:56 by crevette          #+#    #+#             */
/*   Updated: 2026/03/17 16:39:13 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_ctx(t_ctx *ctx, char **envp)
{
	ctx->env = envp;
	ctx->exit = false;
	if (ctx->env && ctx->env->data)
		ft_env_set(ctx->env, "?=0");
}
