/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_track_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 20:24:51 by crevette          #+#    #+#             */
/*   Updated: 2026/05/09 12:03:57 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/ctx/ctx.h"
#include "exec.h"
#include <unistd.h>

unsigned int	track_node(t_cmd_node *node, t_ctx *ctx)
{
	t_exec_ctx		exec_ctx;
	unsigned int	exit_code;

	exit_code = -1;
	init_exec_ctx(&exec_ctx);
	if (node->kind == PIPELINE)
	{
		exec_ctx.is_pipe = true;
		exit_code = handle_pipe_sign(node, &exec_ctx, ctx);
	}
	else
	{
		exec_ctx.is_pipe = false;
		if (node->kind == COMMAND)
			exit_code = handle_single_command(node, ctx, &exec_ctx);
		if (node->kind == OP_AND)
			exit_code = handle_and_sign(node, ctx);
		if (node->kind == OP_OR)
			exit_code = handle_or_sign(node, ctx);
	}
	return (exit_code);
}
