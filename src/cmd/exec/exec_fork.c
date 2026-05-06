/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 21:35:14 by Oery              #+#    #+#             */
/*   Updated: 2026/05/06 18:19:34 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "src/env/env.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// FIXME: Wrong error when running $PWD
// > execve: Permission denied
// > bash: /home/oery/Documents/42/minishell: Is a directory

static void to_dup_and_close(t_exec_ctx *exec, bool is_redir_in)
{
	int	dup;

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

static void	redir_fd(t_exec_ctx *exec)
{
	if (exec->redir == READ_IN)
		to_dup_and_close(exec, true);
	if (exec->redir == WRITE_OUT)
		to_dup_and_close(exec, false);
	if (exec->redir == HEREDOC)
		to_dup_and_close(exec, true);
	if (exec->redir == APPEND)
		to_dup_and_close(exec, false);
	else if (exec->redir == NO_REDIR)
		return ;
	exec->redir = NO_REDIR;
}

static void	get_and_exec_cmd(char *argv[], t_exec_ctx *exec, t_env *env)
{
	char	*cmd_path;

	cmd_exec_get_path(argv[0], exec, env);
	cmd_path = exec->cmd.path;
	if (!cmd_path)
	{
		ft_dprintf(2, "minishell: '%s': %s\n", argv[0], strerror(errno));
		exit(errno);
	}
	execve(cmd_path, argv, (char **)env->data);
	perror("execve");
	exit(errno);
}

pid_t	cmd_exec_fork(char *argv[], t_exec_ctx *exec, t_env *env)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (perror("pid"), pid);
	else if (pid == 0)
	{
		redir_fd(exec);
		get_and_exec_cmd(argv, exec, env);
		free_cmd_path(exec);
	}
	else
		(void)pid;
	return (pid);
}
