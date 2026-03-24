/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 21:11:43 by Oery              #+#    #+#             */
/*   Updated: 2026/03/24 17:42:00 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/cmd.h"
#include "minishell/ctx.h"
#include "minishell/exec.h"
#include "minishell/expand.h"
#include "minishell/parse.h"

// TODO: Free Resources after the command ran
unsigned int	cmd_handle(const char *input, t_ctx *ctx)
{
	t_array	*words;

	words = cmd_parse_command(input);
	if (!words)
		return (1);
	words = cmd_expand_command(ctx->env, words);
	cmd_quotes_remove(words);
	cmd_exec(ctx, words);
	return (0);
}
