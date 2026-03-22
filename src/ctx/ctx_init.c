/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:40:56 by crevette          #+#    #+#             */
/*   Updated: 2026/03/22 21:29:52 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/ctx.h"

void	ctx_init(t_ctx *ctx, char **envp)
{
	ctx->env = ft_env_from(envp);
	ctx->exit = false;
	if (ctx->env && ctx->env->data)
		ft_env_set(ctx->env, "?=0");
}
