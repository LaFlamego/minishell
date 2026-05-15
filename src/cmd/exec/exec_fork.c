/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 21:35:14 by Oery              #+#    #+#             */
/*   Updated: 2026/05/15 16:03:58 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./path/path.h"
#include "exec.h"
#include "src/env/env.h"
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static unsigned int	get_and_exec_cmd(t_array *argv, t_exec_ctx *exec,
		t_env *env)
{
	char			*cmd_path;
	unsigned int	exit_code;

	exit_code = path_get_cmd((char *)argv->data[0], exec, env);
	if (exit_code != 0)
	{
		free_cmd_path(exec);
		exit(exit_code);
	}
	cmd_path = exec->cmd.path;
	execve(cmd_path, (char *const *)argv->data, (char **)env->data);
	perror("minishell: execve");
	free_cmd_path(exec);
	exit(errno);
}

pid_t	cmd_exec_fork(t_array *argv, t_exec_ctx *exec, t_env *env)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (perror("minishell: pid"), pid);
	else if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		redir_fd(exec, false);
		get_and_exec_cmd(argv, exec, env);
	}
	else if (pid > 0)
	{
		if (exec->redir == READ_IN)
			fd_close_reset(&exec->fd.in, NULL, NULL);
		if (exec->redir == HEREDOC)
			fd_close_reset(NULL, NULL, &exec->fd.heredoc);
		if (exec->redir == WRITE_OUT || exec->redir == APPEND)
			fd_close_reset(NULL, &exec->fd.out, NULL);
		free_cmd_path(exec);
	}
	return (pid);
}
