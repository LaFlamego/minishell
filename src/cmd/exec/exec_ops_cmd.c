/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ops_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:08:52 by crevette          #+#    #+#             */
/*   Updated: 2026/04/30 18:44:35 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cmd.h"
#include "../tree/node.h"
#include "src/ctx/ctx.h"
#include <sys/types.h>


// unsigned int	fork_single_cmd(t_ctx *ctx, char *argv)
// {
// 	pid_t			pid;
// 	unsigned int	exit_code;

// 	pid = -1;
// 	if (pid < 0)
// 	{
// 		perror("pid");
// 		return (1);
// 	}
// 	if (pid == 0)
// 		exit_code = cmd_exec(ctx, argv);
// 	if (pid > 0)
// 		(void);
// 	return (exit_code);
// }

unsigned int	handle_single_command(t_cmd_node *node, t_ctx *ctx, t_exec_ctx *exec_ctx)
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
