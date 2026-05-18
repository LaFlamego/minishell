/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 23:49:24 by Oery              #+#    #+#             */
/*   Updated: 2026/05/18 23:52:12 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./builtins.h"
#include "libft.h"
#include "src/ctx/ctx.h"
#include <stdlib.h>
#include <unistd.h>

static int	sort(void *va, void *vb)
{
	return (ft_strcmp(va, vb));
}

static void	write_key(char *kvp)
{
	size_t	i;

	i = 0;
	while (kvp[i] && kvp[i] != '=')
	{
		ft_putchar_fd(kvp[i], 1);
		i++;
	}
}

static void	print_entries(t_ctx *ctx, t_env *env)
{
	size_t	i;
	char	*val;

	i = 0;
	while (i < env->size)
	{
		if (export_is_valid_arg(env->data[i]))
		{
			ft_printf("declare -x ");
			write_key(env->data[i]);
			val = env_get(ctx->env, env->data[i]);
			if (val)
				ft_printf("=\"%s\"", val);
			ft_printf("\n");
		}
		i++;
	}
}

int	export_print_vars(t_ctx *ctx)
{
	t_array	env;

	env.size = ctx->env->size - 1;
	env.data = malloc(env.size * sizeof(void *));
	if (!env.data)
		return (1);
	ft_memcpy(env.data, ctx->env->data, env.size * sizeof(void *));
	ft_array_sort(&env, &sort);
	print_entries(ctx, &env);
	free(env.data);
	return (0);
}
