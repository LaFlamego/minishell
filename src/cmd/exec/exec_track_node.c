/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_track_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 20:24:51 by crevette          #+#    #+#             */
/*   Updated: 2026/04/25 23:38:40 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cmd.h"
#include "../tree/node.h"
#include "src/ctx/ctx.h"
#include <unistd.h>

//TODO < > << >>
//TODO (DONE)pass fd to proceed

unsigned int	track_node(t_cmd_node *node, t_ctx *ctx)
{
	t_fds	argv_fd;

	// if (!node)
	// 	return(1);
	if (node->kind == COMMAND)
		handle_single_command(node);
	if (node->kind == OP_AND)
		handle_and_sign(node);
	if (node->kind == OP_OR)
		handle_or_sign(node);
	if (node->kind == OP_REDIRECT_IN)
		handle_input_sign();
	if (node->kind == OP_REDIRECT_OUT)
		handle_output_sign();
	if (node->kind == OP_REDIRECT_IN_UNTIL)
		handle_heredoc_sign();
	if (node->kind == OP_REDIRECT_OUT_APPEND)
		handle_append_sign();
	if (node->kind == PIPELINE)
		handle_pipe_sign(node, &argv_fd);
}
