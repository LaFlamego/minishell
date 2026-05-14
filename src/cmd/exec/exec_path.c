/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 13:59:50 by crevette          #+#    #+#             */
/*   Updated: 2026/05/14 18:21:57 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "libft.h"
#include "src/env/env.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

enum						e_access_result
{
	OK,
	FILE_NOT_FOUND,
	ACCESS_DENIED,
	CMD_NOT_FOUND,
};

static enum e_access_result	can_execute(char *path)
{
	if (access(path, F_OK) != 0)
		return (CMD_NOT_FOUND);
	if (access(path, X_OK) != 0)
		return (ACCESS_DENIED);
	return (OK);
}

static char	*get_binary_path(t_env *env, char *cmd, enum e_access_result *last)
{
	char	*var;
	char	*cmd_path;
	char	**paths;
	size_t	i;

	var = env_get(env, "PATH=");
	if (!var)
		return (NULL);
	paths = ft_split(var, ':');
	i = 0;
	if (!paths[0])
	{
		free_splits(paths);
		*last = can_execute(cmd);
		if (*last == OK)
			return (ft_strdup(cmd));
		if (*last == CMD_NOT_FOUND)
			*last = FILE_NOT_FOUND;
		return (NULL);
	}
	while (paths && paths[i])
	{
		cmd_path = ft_format("%s/%s", paths[i], cmd);
		if (!cmd_path)
			break ;
		*last = can_execute(cmd_path);
		if (*last == OK)
		{
			free_splits(paths);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	free_splits(paths);
	return (NULL);
}

static unsigned int	find_command_path(t_exec_ctx *ctx, char *cmd, t_env *env)
{
	enum e_access_result	last;
	char					*path;

	last = OK;
	path = get_binary_path(env, cmd, &last);
	if (!path)
	{
		if (last == ACCESS_DENIED)
		{
			ft_dprintf(2, "minishell: %s: Permission denied\n", cmd);
			return (126);
		}
		if (last == CMD_NOT_FOUND)
		{
			ft_dprintf(2, "minishell: %s: command not found\n", cmd);
			return (127);
		}
		if (last == FILE_NOT_FOUND)
		{
			ft_dprintf(2, "minishell: %s: No such file or directory\n", cmd);
			return (127);
		}
		return (1);
	}
	ctx->cmd.path = path;
	return (0);
}

unsigned int	cmd_exec_get_path(char *cmd, t_exec_ctx *exec, t_env *env)
{
	struct stat	sb;

	if (!ft_strchr(cmd, '/'))
	{
		return (find_command_path(exec, cmd, env));
	}
	if (stat(cmd, &sb) == -1)
	{
		ft_dprintf(2, "minishell: %s: %s\n", cmd, strerror(errno));
		return (1);
	}
	if ((sb.st_mode & S_IFMT) == S_IFDIR)
	{
		ft_dprintf(2, "minishell: %s: Is a directory\n", cmd);
		return (126);
	}
	if (access(cmd, F_OK) != 0)
	{
		ft_dprintf(2, "minishell: %s: No such file or directory\n", cmd);
		return (127);
	}
	if (access(cmd, X_OK) != 0)
	{
		ft_dprintf(2, "minishell: %s: Permission denied\n", cmd);
		return (1);
	}
	return (exec->cmd.path = cmd, 0);
}
