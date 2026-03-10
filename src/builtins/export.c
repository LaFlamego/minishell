/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 21:21:12 by crevette          #+#    #+#             */
/*   Updated: 2026/03/10 22:08:27 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdbool.h>
#include <stdlib.h>

//export: `23=1': not a valid identifier
//export: `23': not a valid identifier
//export: `=': not a valid identifier

static bool	is_valid_args(char *args, int key_end)
{
	int			i;

	if (!ft_isalpha(args[0]) || args[0] != '_')
		return (false);
	i = 1;
	while (args[i] && args[i] != '=')
	{
		if (!ft_isalpha(args[i]) && !ft_isdigit(args[i])
			&& args[i] != '_')
			return (false);
		++i;
	}
	if (args[i] && args[i] == '=')
		key_end = i;
	return (true);
}

static void	store_keypairs(int key_end, char **argv)
{
	int			len;
	char		*key;
	char		*val;

	len = ft_strlen(*argv);
	if (key_end > 0)
	{
		key = ft_substr((*argv), 0, (size_t)key_end);
		if (key_end == len - 1)
			val = ft_strdup("""");
		else
			val = ft_substr((*argv), (size_t)key_end + 1, len - key_end - 1);
	}
	else if (key_end == 0)
		key = argv;
	ft_env_set(key, val);
}

static void	export_list(t_ctx *ctx)
{
	size_t	i;

	i = 0;
	while (i < ctx->env->size)
	{
		printf("%s\n", (char *)ctx->env->data[i]);
		i++;
	}
}

void	mini_export(int argc, char **argv, t_ctx *ctx)
{
	static int	key_end;

	if (argc > 1)
	{	
		++argv;
		while (*argv)
		{
			if (!is_valid_args(*argv, key_end))
			{		
				printf("export: `%s': not a valid identifier\n", (*argv));
				return ;
			}
			store_keypairs(key_end, argv);
			++argv;
		}
	}
	else
		export_list(ctx);
}
