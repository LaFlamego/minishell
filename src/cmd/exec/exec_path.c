/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 13:59:50 by crevette          #+#    #+#             */
/*   Updated: 2026/03/22 21:40:28 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell/env.h"
#include <stdlib.h>
#include <unistd.h>

static char	**extract_path(char **envp)
{
	char	*path_str;
	char	**res;

	if (!envp || !*envp)
		return (NULL);
	path_str = NULL;
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			path_str = *envp + 5;
			break ;
		}
		++envp;
	}
	if (!path_str)
		return (NULL);
	res = ft_split(path_str, ':');
	return (res);
}

static bool	cmd_access(char *target_path)
{
	if (access(target_path, F_OK) == 0)
	{
		return (true);
		// if (access(target_path, X_OK) == 0)
		// 	return (true);
		// else
		// 	f_no_x = true;
		// TODO return for permission issue and free
	}
	return (false);
}

static char	*find_path(char *cmd_name, char **cddt_paths)
{
	char	*tpr;
	char	*res;

	if (cddt_paths)
	{
		while (*cddt_paths)
		{
			tpr = ft_strjoin(*cddt_paths, "/");
			if (!tpr)
				return (NULL);
			res = ft_strjoin(tpr, cmd_name);
			free(tpr);
			if (!res)
				return (NULL);
			if (cmd_access(res))
				return (res);
			free(res);
			++cddt_paths;
		}
	}
	return (NULL);
}

char	*cmd_exec_get_path(char *cmd_name, t_env *env)
{
	char	*path;
	char	*path_find;
	char	**cddt_paths;

	if (!cmd_name)
		return (NULL);
	// cmd->is_abs = false;
	path = ft_strchr(cmd_name, '/');
	cddt_paths = extract_path((char **)env->data);
	path_find = find_path(cmd_name, cddt_paths);
	if (cddt_paths)
		free_splits(cddt_paths);
	if (path)
	{
		path = cmd_name;
		// cmd->is_abs = true;
		if (access(path, X_OK) == 0 && access(path, F_OK) == 0)
			return (path);
	}
	else if (path_find)
		return (path_find);
	return (NULL);
}
