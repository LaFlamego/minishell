/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 21:35:14 by Oery              #+#    #+#             */
/*   Updated: 2026/05/08 19:33:16 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "src/env/env.h"
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// FIXME: Wrong error when running $PWD
// > execve: Permission denied
// > bash: /home/oery/Documents/42/minishell: Is a directory

static void	get_and_exec_cmd(char *argv[], t_exec_ctx *exec, t_env *env)
{
	char	*cmd_path;

	cmd_exec_get_path(argv[0], exec, env);
	cmd_path = exec->cmd.path;
	if (!cmd_path)
	{
		//ft_dprintf(2, "minishell: '%s': %s\n", argv[0], strerror(errno));
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
		redir_fd(exec, false);
		get_and_exec_cmd(argv, exec, env);
		free_cmd_path(exec);
	}
	else
		(void)pid;
	return (pid);
}
