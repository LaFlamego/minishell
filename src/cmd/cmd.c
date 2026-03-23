/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 21:11:43 by Oery              #+#    #+#             */
/*   Updated: 2026/03/23 04:12:07 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell/ctx.h"
#include "minishell/exec.h"
#include "minishell/expand.h"
#include "minishell/parse.h"
#include <stdlib.h>

// FIXME: This might be adding a NULL as argument
static char	**get_argv(t_array *words)
{
	size_t		i;
	t_array		argv;
	t_string	*word;

	ft_bzero(&argv, sizeof(t_array));
	i = 0;
	while (i < words->size)
	{
		word = words->data[i];
		ft_array_push(&argv, word->content);
		i++;
	}
	return ((char **)argv.data);
}

// FIXME: I have no idea what's going on.
// > words->data is just random garbage for some reason
// TODO: Free Resources after the command ran
unsigned int	cmd_handle(const char *input, t_ctx *ctx)
{
	t_array	*words;
	char	**argv;
	int		argc;

	words = cmd_parse_command(input);
	if (!words)
		return (1);
	words = cmd_expand_command(ctx->env, words);
	argc = (int)words->size;
	argv = get_argv(words);
	cmd_exec(ctx, argc, argv);
	return (0);
}
