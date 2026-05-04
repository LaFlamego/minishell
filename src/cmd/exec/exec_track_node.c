/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_track_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 20:24:51 by crevette          #+#    #+#             */
/*   Updated: 2026/05/04 20:44:59 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/ctx/ctx.h"
#include "exec.h"
#include <unistd.h>

unsigned int	track_node(t_cmd_node *node, t_ctx *ctx)
{
	t_exec_ctx	exec_ctx;

	init_exec_ctx(&exec_ctx);
	if (node->kind == COMMAND)
		handle_single_command(node, ctx, &exec_ctx);
	if (node->kind == PIPELINE)
		handle_pipe_sign(node, &exec_ctx);
	if (node->kind == OP_AND)
		handle_and_sign(node);
	if (node->kind == OP_OR)
		handle_or_sign(node);
}
