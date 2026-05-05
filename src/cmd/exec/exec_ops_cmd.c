/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ops_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:08:52 by crevette          #+#    #+#             */
/*   Updated: 2026/05/05 19:49:07 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include "exec.h"
#include "../expand/expand.h"

unsigned int	handle_single_command(t_cmd_node *node, t_ctx *ctx, t_exec_ctx *exec_ctx)
{
	t_array			*argv;
	unsigned int	exit_code;

	argv = expand_command(node->data, ctx->env, exec_ctx);
	if (!argv)
		return (1);
	exit_code = cmd_exec(ctx, exec_ctx, argv);
	return (exit_code);
}
