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

#include "minishell/ctx.h"
#include "minishell/exec.h"
#include "minishell/expand.h"
#include "minishell/parse.h"

// FIXME: I have no idea what's going on.
// > words->data is just random garbage for some reason
// TODO: Free Resources after the command ran
unsigned int	cmd_handle(const char *input, t_ctx *ctx)
{
	t_array	*words;
	void	**argv;
	int		argc;

	words = cmd_parse_command(input);
	if (!words)
		return (1);
	words = cmd_expand_command(ctx->env, words);
	argc = (int)words->size;
	argv = (words->data);
	cmd_exec(ctx, argc, (char **)argv);
	return (0);
}
