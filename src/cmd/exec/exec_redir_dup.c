/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir_dup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 14:27:44 by crevette          #+#    #+#             */
/*   Updated: 2026/05/15 20:03:35 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <stdio.h>
#include <unistd.h>

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

static void	to_dup_and_close(t_exec_ctx *exec, bool is_redir_in,
		bool to_save_stdio)
{
	int	dup;

	dup = -1;
	save_stdio(exec, is_redir_in, to_save_stdio);
	if (exec->redir == READ_IN && exec->fd.in != -1)
		dup = dup2(exec->fd.in, STDIN_FILENO);
	if (exec->redir == HEREDOC && exec->fd.heredoc != -1)
		dup = dup2(exec->fd.heredoc, STDIN_FILENO);
	if (!is_redir_in && exec->fd.out != -1)
		dup = dup2(exec->fd.out, STDOUT_FILENO);
	fd_close_reset(&exec->fd.in, &exec->fd.out, &exec->fd.heredoc);
	if (dup == -1)
	{
		perror("minishell: dup");
		return ;
	}
}

void	redir_fd(t_exec_ctx *exec, bool to_save_stdio)
{
	if (exec->redir == READ_IN || exec->redir == HEREDOC)
		to_dup_and_close(exec, true, to_save_stdio);
	if (exec->redir == WRITE_OUT || exec->redir == APPEND)
		to_dup_and_close(exec, false, to_save_stdio);
	else if (exec->redir == NO_REDIR)
		return ;
	exec->redir = NO_REDIR;
}
