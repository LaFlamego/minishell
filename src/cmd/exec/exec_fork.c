/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 21:35:14 by Oery              #+#    #+#             */
/*   Updated: 2026/05/10 19:54:36 by crevette         ###   ########.fr       */
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

static unsigned int	get_and_exec_cmd(t_array *argv, t_exec_ctx *exec, t_env *env)
{
	char			*cmd_path;
	unsigned int	exit_code;

	exit_code = cmd_exec_get_path((char *)argv->data[0], exec, env);
	if (exit_code != 0)
	{
		free_cmd_path(exec);
		ft_array_free(argv, free);
		exit(exit_code);
	}
	cmd_path = exec->cmd.path;
	// if (!cmd_path)
	// {
	// 	ft_dprintf(2, "minishell: '%s': %s\n", argv[0], strerror(errno));
	// 	exit(errno);
	// }
	execve(cmd_path, (char * const*)argv->data, (char **)env->data);
	perror("execve");
	free_cmd_path(exec);
	ft_array_free(argv, free);
	exit(errno);
}

pid_t	cmd_exec_fork(t_array *argv, t_exec_ctx *exec, t_env *env)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (perror("pid"), pid);
	else if (pid == 0)
	{
		redir_fd(exec, false);
		get_and_exec_cmd(argv, exec, env);
	}
	else if (pid > 0)
		free_cmd_path(exec);
	return (pid);
}
