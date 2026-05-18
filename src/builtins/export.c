/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 21:21:12 by crevette          #+#    #+#             */
/*   Updated: 2026/05/18 23:51:59 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./builtins.h"
#include "libft.h"
#include "src/ctx/ctx.h"
#include <unistd.h>

bool	export_is_valid_arg(char *arg)
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

static int	export_variables(int argc, char **argv, t_ctx *ctx)
{
	int		i;
	int		exit_code;
	char	*value;

	i = 1;
	exit_code = 0;
	while (i < argc)
	{
		if (export_is_valid_arg(argv[i]))
		{
			value = env_get(ctx->env, argv[i]);
			if (!value || ft_strchr(argv[i], '='))
				env_set(ctx->env, argv[i]);
		}
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
		return (export_print_vars(ctx));
	}
	else
	{
		return (export_variables(argc, argv, ctx));
	}
}
