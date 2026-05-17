/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:40:56 by crevette          #+#    #+#             */
/*   Updated: 2026/05/17 23:40:39 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ctx.h"
#include "src/utils/utils.h"
#include <termios.h>
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

static void	init_term(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

int	ctx_init(t_ctx *ctx, char **envp)
{
	init_term();
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
