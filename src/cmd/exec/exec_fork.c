/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 21:35:14 by Oery              #+#    #+#             */
/*   Updated: 2026/04/02 01:24:20 by Oery             ###   ########.fr       */
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
pid_t	cmd_exec_fork(char *argv[], t_env *env)
{
	char	*cmd_path;
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		return (perror("pid"), pid);
		// TODO free cmd
	}
	else if (pid == 0)
	{
		cmd_path = cmd_exec_get_path(argv[0], env);
		if (!cmd_path)
		{
			ft_dprintf(2, "minishell: '%s': %s\n", argv[0], strerror(errno));
			exit(errno);
		}
		execve(cmd_path, argv, (char **)env->data);
		perror("execve");
		exit(errno);
		// TODO free cmd
	}
	else
		(void)pid;
	return (pid);
}
