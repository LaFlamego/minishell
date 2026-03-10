/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 21:21:12 by crevette          #+#    #+#             */
/*   Updated: 2026/03/10 23:33:53 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// FIXME: Error Message should probably be written to stderr
void	mini_export(int argc, char **argv, t_ctx *ctx)
{
	size_t	i;

	if (argc <= 1)
	{
		export_list(ctx);
		return ;
	}
	else
	{
		i = 1;
		while (argv[i])
		{
			if (is_valid_arg(argv[i]))
				store_keypair(ctx, argv[i]);
			else
				printf("export: `%s': not a valid identifier\n", argv[i]);
			++i;
		}
	}
}
