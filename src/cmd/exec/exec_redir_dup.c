/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir_dup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 14:27:44 by crevette          #+#    #+#             */
/*   Updated: 2026/05/08 20:34:23 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <unistd.h>
#include <stdio.h>

void	save_stdio(t_exec_ctx *exec, bool is_redir_in, bool to_save_stdio)
{
	if (to_save_stdio && is_redir_in)
		exec->fd.stdin_tpr = dup(STDIN_FILENO);
	if (to_save_stdio && !is_redir_in)
		exec->fd.stdout_tpr = dup(STDOUT_FILENO);
}

void	restore_stdio(t_exec_ctx *exec)
{
	if (exec->fd.stdin_tpr != -1)
	{
		dup2(exec->fd.stdin_tpr, STDIN_FILENO);
		close(exec->fd.stdin_tpr);
		exec->fd.stdin_tpr = -1;
	}
	if (exec->fd.stdout_tpr != -1)
	{
		dup2(exec->fd.stdout_tpr, STDOUT_FILENO);
		close(exec->fd.stdout_tpr);
		exec->fd.stdout_tpr = -1;
	}
}

static void	to_dup_and_close(t_exec_ctx *exec, bool is_redir_in, bool to_save_stdio)
{
	int	dup;

	save_stdio(exec, is_redir_in, to_save_stdio);
	if (is_redir_in && exec->fd.in != -1)
		dup = dup2(exec->fd.in, STDIN_FILENO);
	if (!is_redir_in && exec->fd.out != -1)
		dup = dup2(exec->fd.out, STDOUT_FILENO);
	if (dup == -1)
	{
		fd_close_reset(&exec->fd.in, &exec->fd.out, &exec->pipe.fd);
		perror("dup");
		return ;
	}
	if (is_redir_in)
		fd_close_reset(&exec->fd.in, NULL, NULL);
	else
		fd_close_reset(NULL, &exec->fd.out, NULL);
}

void	redir_fd(t_exec_ctx *exec, bool to_save_stdio)
{
	if (exec->redir == READ_IN)
		to_dup_and_close(exec, true, to_save_stdio);
	if (exec->redir == WRITE_OUT)
		to_dup_and_close(exec, false, to_save_stdio);
	if (exec->redir == HEREDOC)
		to_dup_and_close(exec, true, to_save_stdio);
	if (exec->redir == APPEND)
		to_dup_and_close(exec, false, to_save_stdio);
	else if (exec->redir == NO_REDIR)
		return ;
	exec->redir = NO_REDIR;
}
