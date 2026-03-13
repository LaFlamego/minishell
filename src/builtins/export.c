/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 21:21:12 by crevette          #+#    #+#             */
/*   Updated: 2026/03/13 18:10:52 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft/printf.h"
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

// Last element of env is NULL
// > Therefore we stop at i = size - 1
// FIXME: Values should be printed between double quotes
void	env_vars_list(t_ctx *ctx)
{
	size_t	i;

	i = 0;
	while (i < ctx->env->size - 1)
	{
		if (is_valid_arg((char *)ctx->env->data[i]))
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
			ft_env_set(ctx->env, argv[i]);
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
		env_vars_list(ctx);
		exit_code = 0;
	}
	else
	{
		exit_code = export_variables(argc, argv, ctx);
	}
	return (exit_code);
}
