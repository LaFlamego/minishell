/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ops_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:08:52 by crevette          #+#    #+#             */
/*   Updated: 2026/05/04 18:29:27 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include "exec.h"

unsigned int	handle_single_command(t_cmd_node *node, t_ctx *ctx, t_exec_ctx *exec_ctx)
{
	t_array			*cmd_node;
	unsigned int	exit_code;
	char			**argv;

	cmd_node = node->data;
	argv = expand_args(cmd_node->data);
	if (!argv)
		return (1);
	return (cmd_exec(ctx, exec_ctx, argv));
}
