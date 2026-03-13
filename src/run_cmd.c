/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 21:02:13 by crevette          #+#    #+#             */
/*   Updated: 2026/03/13 20:35:05 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/env.h"
#include <sys/types.h>

char	*get_path(char *cmd_name, t_env *env);

unsigned	wait_exit_code(pid_t pid)
{
	int			status;
	unsigned	exit_code;
	pid_t		pid_wait;

	exit_code = 0;
	pid_wait = waitpid(pid, &status, 0);
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
		// TODO free
	}
	else if (pid == 0)
	{
		cmd_path = get_path(cmds[0], env);
		if (!cmd_path);
			return ;
		execve(cmd_path, cmds, env->data);
		return(perror("execve"), pid);
		// TODO free
	}
	else
		(void)pid;
	return (pid);
}

unsigned	run_cmd(char **cmds, t_env *env)
{
	pid_t		pid;
	unsigned	exit_code;

	pid = fork_to_cmd(cmds, env);
	exit_code = wait_exit_code(pid);
	return (exit_code);
}
