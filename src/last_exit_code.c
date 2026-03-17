/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_exit_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 12:55:09 by crevette          #+#    #+#             */
/*   Updated: 2026/03/17 12:55:41 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "libft/string.h"

void	add_q_env_var(t_ctx *ctx)
{
	if (ctx->env && ctx->env->data)
		ft_env_set(ctx->env, "?=0");
}

int	update_exit_code(unsigned int exit_code, t_ctx *ctx)
{
	t_string var;
	char *val;

	if (exit_code)
	{
		var = ft_string_from_cstring_alloc("?=");
		if (!var.content)
			return (1);
		val = ft_itoa(exit_code);
		if (!val)
			return (1);
		ft_string_push_str(&var, val);
		free(val);
		ft_string_push(&var, '\0');
		ft_env_set(ctx->env, var.content);
		free(var.content);
	}
	return (0);
}
