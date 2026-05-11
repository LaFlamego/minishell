/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ops_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:08:52 by crevette          #+#    #+#             */
/*   Updated: 2026/05/11 17:13:11 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../expand/expand.h"
#include "exec.h"
#include "src/debug/debug.h"
#include <stdlib.h>
#include <sys/types.h>

unsigned int	handle_single_command(t_cmd_node *node, t_ctx *ctx,
		t_exec_ctx *exec_ctx)
{
	t_array			*argv;
	unsigned int	exit_code;

	argv = expand_command(node->data, exec_ctx);
	if (!argv)
		return (1);
	if (ctx->flags & FLAG_DEBUG)
		debug_argv(argv);
	if (argv->size <= 1)
		exit_code = 0;
	else
		exit_code = cmd_exec(ctx, exec_ctx, argv);
	ft_array_free(argv, free);
	return (exit_code);
}
