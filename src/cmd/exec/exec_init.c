/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 10:13:53 by crevette          #+#    #+#             */
/*   Updated: 2026/05/11 22:58:38 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "libft.h"

void	init_exec_ctx(t_exec_ctx *exec, t_ctx *ctx)
{
	ft_bzero(exec, sizeof(t_exec_ctx));
	exec->redir = NO_REDIR;
	exec->is_pipe = false;
	exec->cmd.path = NULL;
	exec->fd.in = -1;
	exec->fd.out = -1;
	exec->fd.stdin_tpr = -1;
	exec->fd.stdout_tpr = -1;
	exec->fd.heredoc = -1;
	exec->pipe.fd = -1;
	exec->pipe.index = 0;
	exec->env = ctx->env;
	exec->shell = ctx;
}
