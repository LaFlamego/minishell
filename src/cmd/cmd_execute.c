/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 21:02:13 by crevette          #+#    #+#             */
/*   Updated: 2026/03/17 16:41:52 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/env.h"
#include "libft/printf.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char	*get_path(char *cmd_name, t_env *env);

unsigned	wait_exit_code(pid_t pid)
{
	int			status;
	unsigned	exit_code;
	//pid_t		pid_wait;

	exit_code = 0;
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		exit_code = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		exit_code = WTERMSIG(status) + 128;
	return (exit_code);
}

pid_t	fork_to_cmd(char **cmds, t_env *env)
{
	char	*cmd_path;
	pid_t		pid;

	pid = fork();
	if (pid < 0)
	{
		return (perror("pid"), pid);
		// TODO free cmd
	}
	else if (pid == 0)
	{
		cmd_path = get_path(cmds[0], env);
		if (!cmd_path)
		{
			ft_dprintf(2, "minishell: '%s': %s\n", cmds[0], strerror(errno));
			exit(errno);
		}
		execve(cmd_path, cmds, (char **)env->data);
		perror("execve");
		exit(errno);
		// TODO free cmd
	}
	else
		(void)pid;
	return (pid);
}

unsigned	cmd_execute(char **cmds, t_env *env)
{
	pid_t		pid;
	unsigned	exit_code;

	pid = fork_to_cmd(cmds, env);
	exit_code = wait_exit_code(pid);
	return (exit_code);
}
