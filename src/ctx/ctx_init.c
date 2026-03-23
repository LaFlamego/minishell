/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:40:56 by crevette          #+#    #+#             */
/*   Updated: 2026/03/23 04:26:06 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/ctx.h"

void	ctx_init(t_ctx *ctx, char **envp)
{
	ctx->env = env_from(envp);
	ctx->exit = false;
	if (ctx->env && ctx->env->data)
		env_set(ctx->env, "?=0");
}
