/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 21:11:43 by Oery              #+#    #+#             */
/*   Updated: 2026/04/02 01:32:00 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cmd.h"
#include "./parser/parser.h"
#include "src/cmd/exec/exec.h"
#include "src/ctx/ctx.h"

// #include "minishell/expand.h"

// TODO: AST
// 1. Tokenize the command (is this necessary?)
// 2. Turn it into statements / command

// TODO: Parse Input as a tree
// > words must be an array of cmds, linked with an operator

// TODO: Free Resources after the command ran
unsigned int	cmd_handle(const char *input, t_ctx *ctx)
{
	t_parser	p;

	p = parser_new(input);
	parse_command(&p);
	(void)ctx;
	// words = cmd_parse_command(input);
	// if (!words)
	// 	return (1);
	// words = cmd_expand_command(ctx->env, words);
	// cmd_quotes_remove(words);
	// cmd_exec(ctx, words);
	return (0);
}
