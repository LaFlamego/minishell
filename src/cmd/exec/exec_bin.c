/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 21:02:13 by crevette          #+#    #+#             */
/*   Updated: 2026/03/22 22:04:51 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/env.h"
#include "minishell/exec.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

static unsigned int	wait_exit_code(pid_t pid)
{
	int				status;
	unsigned int	exit_code;

	// pid_t		pid_wait;
	exit_code = 0;
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		exit_code = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		exit_code = WTERMSIG(status) + 128;
	return (exit_code);
}

unsigned int	cmd_exec_bin(char **cmds, t_env *env)
{
	pid_t			pid;
	unsigned int	exit_code;

	pid = cmd_exec_fork(cmds, env);
	exit_code = wait_exit_code(pid);
	return (exit_code);
}
