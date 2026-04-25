/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:39:11 by Oery              #+#    #+#             */
/*   Updated: 2026/04/17 17:22:38 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./expand.h"
#include "libft.h"
#include "src/cmd/tree/node.h"
#include "src/env/env.h"
#include "src/scanner/token/token.h"
#include <stdlib.h>

// WARN: Watch out for errors

char	*expand_arg(t_array *argv, t_array *tokens, t_env *env)
{
	size_t	size;
	char	*arg;

	size = get_arg_expanded_size(tokens, env);
	arg = malloc(size);
	if (!arg)
		return (NULL);
	// TODO: Copy all values
	// > push result char * to argv
	if (!ft_array_push(argv, arg))
	{
		free(arg);
		return (NULL);
	}
	return (arg);
}

static int	expand_args(t_cmd_args *node, t_env *env)
{
	t_array	*argv;
	size_t	i;

	argv = ft_array_new();
	if (!argv)
		return (1);
	i = 0;
	while (i < node->args.size)
	{
		if (!expand_arg(argv, node->args.data[i], env))
		{
			ft_array_foreach(&node->args, token_free);
			return (1);
		};
		i++;
	}
	ft_array_foreach(&node->args, token_free);
	ft_memmove(&node->args, argv, sizeof(t_array));
	free(argv);
	return (0);
}

// TODO: Expand redirections
int	expand_node(t_cmd_args *data)
{
	if (expand_args(data))
		return (1);
	return (0);
}
