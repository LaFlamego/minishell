/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ops_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:08:52 by crevette          #+#    #+#             */
/*   Updated: 2026/04/25 17:14:00 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cmd.h"
#include "../tree/node.h"
#include "src/ctx/ctx.h"

unsigned int	handle_single_command(t_cmd_node *node, t_ctx *ctx)
{
	t_array			*cmd_node;
	unsigned int	exit_code;
	char			**argv;

	cmd_node = node->data;
	argv = expand_args(cmd_node->data);
	if (!argv)
		return (1);
	return (cmd_exec(ctx, argv));
}
