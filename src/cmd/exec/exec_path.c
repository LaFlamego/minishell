/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 13:59:50 by crevette          #+#    #+#             */
/*   Updated: 2026/05/04 18:29:54 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "exec.h"
#include "src/env/env.h"
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

static bool	cmd_access(char *target_path, int *find_no_x, int *no_find)
{
	if (access(target_path, F_OK) == 0)
	{
		*no_find = 0;
		if (access(target_path, X_OK) == 0)
			return (true);
		else
			*find_no_x = 1;
		// TODO return for permission issue and free
	}
	else
		*no_find = 1;
	return (false);
}
static unsigned int	print_if_target_fail(char *cmd_name, int find_no_x, int no_find)
{
	if (find_no_x == 1)
		return(ft_printf("%s: permission denied\n", cmd_name), 126);
	else if (no_find == 1)
		return (ft_printf("%s: command not found\n", cmd_name), 127);
	return (0);
}

static unsigned int	find_path(t_exec_ctx *exec, char *cmd_name, char **cddt_paths)
{
	char	*tpr;
	char	*res;
	int		find_no_x;
	int		no_find;

	find_no_x = 0;
	no_find = 0;
	if (cddt_paths)
	{
		while (*cddt_paths)
		{
			tpr = ft_strjoin(*cddt_paths, "/");
			if (!tpr)
				return (1);
			res = ft_strjoin(tpr, cmd_name);
			free(tpr);
			if (!res)
				return (1);
			if (cmd_access(res, &find_no_x, &no_find))
				return (exec->cmd.path = res, 0);
			free(res);
			++cddt_paths;
		}
	}
	return (print_if_target_fail(cmd_name, find_no_x, no_find));
}

unsigned int	*cmd_exec_get_path(char *cmd_name, t_exec_ctx *exec, t_env *env)
{
	char	*path_find;
	char	**cddt_paths;

	if (!cmd_name)
		return (ft_printf("'': command not found\n"), 127);
	if (ft_strchr(cmd_name, '/'))
	{
		if (access(cmd_name, X_OK) == 0 && access(cmd_name, F_OK) == 0)
			exec->cmd.path = cmd_name;
		else
			return (ft_printf("%s: No such file or directory\n", cmd_name), 127);
	}
	cddt_paths = extract_path((char **)env->data);
	if (!cddt_paths)
		return (1);
	path_find = find_path(exec, cmd_name, cddt_paths);
	if (!path_find)
		return (free_splits(cddt_paths), 
			ft_printf("%s: command not found\n", cmd_name), 127);
	free_splits(cddt_paths);
	if (path_find)
		exec->cmd.path = path_find;
	return (0);
}
