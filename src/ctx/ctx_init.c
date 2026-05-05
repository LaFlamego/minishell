/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:40:56 by crevette          #+#    #+#             */
/*   Updated: 2026/05/03 17:39:04 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ctx.h"
#include "src/utils/utils.h"
#include <stdlib.h>

// TODO: add format! to libft

int	ctx_free(t_ctx *ctx)
{
	env_free(ctx->env);
	return (0);
}

// TODO: rename this
char	*ssss(char *key, char *val, t_env *env)
{
	t_string	*s;
	char		*content;
	size_t		size;

	size = ft_strlen(key) + ft_strlen(val);
	s = ft_string_new(size);
	if (!s || ft_string_push_str(s, "PWD="))
		return (NULL);
	ft_string_push_str(s, val);
	content = s->content;
	env_set(env, content);
	free(s);
	return (content);
}

static int	set_shell_variables(t_env *env)
{
	char	*pwd;

	if (!env_set(env, "?=0"))
		return (0);
	if (!env_set(env, "HISTFILE=minishell_history.txt"))
		return (0);
	pwd = get_pwd();
	if (!pwd)
	{
		// handle error
	}
	// add pwd
	if (!env_set(env, ""))
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
	// WARN: history_load(ctx->env);
	if (!setup_signals_handlers())
		return (ctx_free(ctx));
	return (1);
}
