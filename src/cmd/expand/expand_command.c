/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:39:11 by Oery              #+#    #+#             */
/*   Updated: 2026/05/15 16:25:07 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./expand.h"
#include "src/cmd/tree/word/word.h"
#include "src/env/env.h"
#include <stdint.h>
#include <stdlib.h>

int	expand_variable(t_string *arg, char *key, t_env *env)
{
	char	*value;

	value = env_get(env, key);
	if (!value)
		return (1);
	if (!ft_string_push_str(arg, value))
		return (0);
	return (1);
}

t_array	*expand_command(t_word *words, t_exec_ctx *ctx)
{
	t_word	*curr;
	t_array	*argv;

	argv = ft_array_new();
	if (!argv)
		return (NULL);
	curr = words;
	while (curr)
	{
		if (!expand_word(curr->content, argv, ctx))
		{
			ft_array_free(argv, free);
			return (NULL);
		}
		curr = curr->next;
	}
	if (!ft_array_push(argv, NULL))
	{
		ft_array_free(argv, free);
		return (NULL);
	}
	return (argv);
}
