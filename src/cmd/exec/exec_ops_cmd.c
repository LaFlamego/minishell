/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ops_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:08:52 by crevette          #+#    #+#             */
/*   Updated: 2026/04/29 23:08:32 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cmd.h"
#include "../tree/node.h"
#include "src/ctx/ctx.h"
#include <sys/types.h>


pid_t	fork_single_cmd()
{
	pid_t			pid;

	pid = -1;
	if (pid < 0)
	{
		perror("pid");
	}
	if (pid == 0)
	{

	}
	if (pid > 0)
	{

	}
}

unsigned int	handle_single_command(t_cmd_node *node, t_ctx *ctx, t_exec_ctx *exec_ctx)
{
	t_array			*cmd_node;
	unsigned int	exit_code;
	char			**argv;

	cmd_node = node->data;
	argv = expand_args(cmd_node->data);
	if (!argv)
		return (1);
	if (exec_ctx->is_pipe_cmd == true)
		return (cmd_exec(ctx, argv));
	else
	{
		//TODO fork for each cmd

	}
		
}
