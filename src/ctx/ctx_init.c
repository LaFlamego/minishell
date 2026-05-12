/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:40:56 by crevette          #+#    #+#             */
/*   Updated: 2026/05/12 21:03:55 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ctx.h"
#include "src/utils/utils.h"
#include <unistd.h>

int	ctx_free(t_ctx *ctx)
{
	env_free(ctx->env);
	return (0);
}

static int	set_shell_variables(t_env *env)
{
	if (!env_set(env, "?=0"))
		return (0);
	return (1);
}

int	ctx_init(t_ctx *ctx, char **envp)
{
	ft_bzero(ctx, sizeof(t_ctx));
	ctx->exit = false;
	ctx->env = env_from(envp);
	if (!ctx->env)
		return (ctx_free(ctx));
	if (!set_shell_variables(ctx->env))
		return (ctx_free(ctx));
	if (!setup_signals_handlers())
		return (ctx_free(ctx));
	return (1);
}
