/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_get_bin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 15:32:12 by Oery              #+#    #+#             */
/*   Updated: 2026/05/15 16:04:43 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./path.h"
#include "./src/env/env.h"
#include <stdlib.h>
#include <unistd.h>

static t_path_res	can_execute(const char *path)
{
	if (!file_exists(path))
		return (CMD_NOT_FOUND);
	if (!has_exe_perm(path))
		return (ACCESS_DENIED);
	return (OK);
}

static char	*check_pwd(char *cmd, t_path_res *last)
{
	*last = can_execute(cmd);
	if (*last == OK)
		return (ft_strdup(cmd));
	if (*last == CMD_NOT_FOUND)
		*last = FILE_NOT_FOUND;
	return (NULL);
}

static char	**get_paths_var_value(t_env *env)
{
	char	*var;
	char	**paths;

	var = env_get(env, "PATH=");
	if (!var)
		return (NULL);
	paths = ft_split(var, ':');
	return (paths);
}

static char	*get_from_paths(char **paths, char *cmd, t_path_res *last)
{
	char	*cmd_path;
	size_t	i;

	i = 0;
	while (paths && paths[i])
	{
		cmd_path = ft_format("%s/%s", paths[i], cmd);
		if (!cmd_path)
			break ;
		*last = can_execute(cmd_path);
		if (*last == OK)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (NULL);
}

char	*path_get_bin(t_env *env, char *cmd, t_path_res *last)
{
	char	*cmd_path;
	char	**paths;

	cmd_path = NULL;
	paths = get_paths_var_value(env);
	if (paths[0])
		cmd_path = get_from_paths(paths, cmd, last);
	else
		cmd_path = check_pwd(cmd, last);
	free_splits(paths);
	return (cmd_path);
}
