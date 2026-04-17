/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 13:59:50 by crevette          #+#    #+#             */
/*   Updated: 2026/04/16 15:32:34 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "src/env/env.h"
#include "cmd.h"
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

static bool	cmd_access(t_cmd *cmd, char *target_path)
{
	cmd->f_no_x = false;
	if (access(target_path, F_OK) == 0)
	{
		if (access(target_path, X_OK) == 0)
			return (true);
		else
			cmd->f_no_x= true;
		// TODO return for permission issue and free
	}
	return (false);
}

static char	*find_path(t_cmd *cmd, char *cmd_name, char **cddt_paths)
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
			if (cmd_access(cmd, res))
				return (res);
			else
				ft_printf("%s: permission denied\n", ctx->args[ctx->cmd.nb + 1]);
				return (126);
			free(res);
			++cddt_paths;
		}
	}
	return (NULL);
}

unsigned int error_print_exit(int  )
{

}

static unsigned int	*path_is_cmd_name(char *cmd_name, t_cmd *cmd)
{
	if (access(cmd_name, X_OK) == 0 && access(cmd_name, F_OK) == 0)
		cmd->path = cmd_name;
	else
	{
		ft_printf("%s: No such file or directory\n", cmd_name);
		return (127);
	}
	return (0);
}

unsigned int	*cmd_exec_get_path(char *cmd_name, t_cmd *cmd, t_env *env)
{
	char	*path_find;
	char	**cddt_paths;

	if (!cmd_name)
		return (ft_printf("'': command not found\n"), 127);
	if (ft_strchr(cmd_name, '/'))
		return (path_is_cmd_name(cmd_name, cmd));
	cddt_paths = extract_path((char **)env->data);
	if (!cddt_paths)
		return (1);
	path_find = find_path(cmd, cmd_name, cddt_paths);
	if (!path_find)
		return (free_splits(cddt_paths), 
			ft_printf("%s: command not found\n", cmd_name), 127);
	free_splits(cddt_paths);
	if (path_find)
		cmd->path = path_find;
	return (0);
}
