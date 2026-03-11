/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 21:21:12 by crevette          #+#    #+#             */
/*   Updated: 2026/03/11 20:31:44 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// export: `23=1': not a valid identifier
// export: `23': not a valid identifier
// export: `=': not a valid identifier

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

// FIXME: We should not store quotes in t_env
static void	store_keypair(t_ctx *ctx, char *var)
{
	char	*val;

	val = ft_strchr(var, '=');
	if (val && *(val + 1) == '\0')
		val = "\"\"";
	else if (val)
		val++;
	ft_env_set(ctx->env, var, val);
}

// Last element of env is NULL
// > Therefore we stop at i = size - 1
// FIXME: Values should be printed between double quotes
// FIXME: Invalid Identifier should be skipped
static void	export_list(t_ctx *ctx)
{
	size_t	i;

	i = 0;
	while (i < ctx->env->size - 1)
	{
		printf("%s\n", (char *)ctx->env->data[i]);
		i++;
	}
}

static int	export_variables(int argc, char **argv, t_ctx *ctx)
{
	int	i;
	int	exit_code;

	i = 1;
	exit_code = 0;
	while (i < argc)
	{
		if (is_valid_arg(argv[i]))
			store_keypair(ctx, argv[i]);
		else
		{
			ft_dprintf(2, "export: `%s': not a valid identifier\n", argv[i]);
			exit_code = 1;
		}
		++i;
	}
	return (exit_code);
}

int	mini_export(int argc, char **argv, t_ctx *ctx)
{
	int	exit_code;

	if (argc <= 1)
	{
		export_list(ctx);
		exit_code = 0;
	}
	else
	{
		exit_code = export_variables(argc, argv, ctx);
	}
	return (exit_code);
}
