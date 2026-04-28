/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:40:56 by crevette          #+#    #+#             */
/*   Updated: 2026/04/28 22:26:31 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ctx.h"
#include "src/utils/utils.h"

static int	set_shell_variables(t_env *env)
{
	if (!env_set(env, "?=0"))
		return (0);
	if (!env_set(env, "HISTFILE=minishell_history.txt"))
		return (0);
	return (1);
}

// FIXME: Free Context on error
int	ctx_init(t_ctx *ctx, char **envp)
{
	ft_bzero(ctx, sizeof(t_ctx));
	ctx->exit = false;
	ctx->env = env_from(envp);
	if (!ctx->env)
		return (0);
	if (!set_shell_variables(ctx->env))
		return (0);
	history_load(ctx->env);
	if (!setup_signals_handlers())
		return (0);
	return (1);
}
