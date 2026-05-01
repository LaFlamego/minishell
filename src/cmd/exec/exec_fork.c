/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 21:35:14 by Oery              #+#    #+#             */
/*   Updated: 2026/05/01 15:31:17 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./exec.h"
#include "src/env/env.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// FIXME: Wrong error when running $PWD
// > execve: Permission denied
// > bash: /home/oery/Documents/42/minishell: Is a directory

static void	redir_setup_fd(t_exec_ctx *exec)
{
	if (exec->redir == READ_IN)
	{

	}
	if (exec->redir == WRITE_OUT)
	{
		
	}
	if (exec->redir == HEREDOC)
	{
		
	}
	if (exec->redir == APPEND)
	{
		
	}
	if (exec->redir == NO_REDIR)
	{
		
	}
}

static void	get_and_exec_cmd(char *argv[], t_exec_ctx *exec, t_env *env)
{
	char	*cmd_path;

	cmd_path = cmd_exec_get_path(argv[0], exec, env);
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
	{
		return (perror("pid"), pid);
		// TODO free cmd
	}
	else if (pid == 0)
	{
		get_and_exec_cmd(argv, exec, env);
		// TODO free cmd
	}
	else
		(void)pid;
	return (pid);
}
