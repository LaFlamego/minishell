/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 21:21:12 by crevette          #+#    #+#             */
/*   Updated: 2026/05/17 18:55:49 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "src/ctx/ctx.h"
#include <stdlib.h>
#include <unistd.h>

// TODO: Does is_valid respect underscore?
static bool	is_valid_arg(char *arg)
{
	int	i;

	if (!ft_isalpha(arg[0]) && arg[0] != '_')
		return (false);
	i = 1;
	while (arg[i] && arg[i] != '=')
	{
		if (!ft_isalpha(arg[i]) && !ft_isdigit(arg[i]) && arg[i] != '_')
			return (false);
		++i;
	}
	return (true);
}

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

// TODO: Can values be NULL?
int	env_vars_list(t_ctx *ctx)
{
	size_t	i;
	char	*val;
	t_array	env;

	env.size = ctx->env->size - 1;
	env.data = malloc(env.size * sizeof(void *));
	if (!env.data)
		return (1);
	ft_memcpy(env.data, ctx->env->data, env.size * sizeof(void *));
	ft_array_sort(&env, &sort);
	i = 0;
	while (i < env.size)
	{
		if (is_valid_arg(env.data[i]))
		{
			ft_printf("declare -x ");
			write_key(env.data[i]);
			val = env_get(ctx->env, env.data[i]);
			if (val)
				ft_printf("=\"%s\"", val);
			ft_printf("\n");
		}
		i++;
	}
	free(env.data);
	return (0);
}

// FIXME: No value should not override previous value
static int	export_variables(int argc, char **argv, t_ctx *ctx)
{
	int	i;
	int	exit_code;

	i = 1;
	exit_code = 0;
	while (i < argc)
	{
		if (is_valid_arg(argv[i]))
			env_set(ctx->env, argv[i]);
		else
		{
			ft_dprintf(2, "minishell: export: `%s': not a valid identifier\n",
				argv[i]);
			exit_code = 1;
		}
		++i;
	}
	return (exit_code);
}

unsigned int	mini_export(int argc, char *argv[], t_ctx *ctx)
{
	if (argc <= 1)
	{
		return (env_vars_list(ctx));
	}
	else
	{
		return (export_variables(argc, argv, ctx));
	}
}
