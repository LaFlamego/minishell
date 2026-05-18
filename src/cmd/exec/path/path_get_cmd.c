/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_get_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 15:07:08 by Oery              #+#    #+#             */
/*   Updated: 2026/05/18 12:52:14 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./path.h"
#include "./src/cmd/exec/exec.h"
#include <sys/stat.h>
#include <unistd.h>

static unsigned int	validate_path(t_exec_ctx *ctx, char *cmd)
{
	struct stat	sb;

	if (stat(cmd, &sb) == -1)
		return (path_error(ERRNO, cmd));
	if ((sb.st_mode & S_IFMT) == S_IFDIR)
		return (path_error(IS_DIR, cmd));
	if (access(cmd, F_OK) != 0)
		return (path_error(FILE_NOT_FOUND, cmd));
	if (access(cmd, X_OK) != 0)
		return (path_error(ACCESS_DENIED, cmd));
	ctx->cmd.path = cmd;
	return (0);
}

unsigned int	path_get_cmd(char *cmd, t_exec_ctx *ctx, t_env *env)
{
	char		*path;
	t_path_res	last;

	if (!cmd[0])
		return (path_error(CMD_NOT_FOUND, cmd));
	if (ft_strchr(cmd, '/'))
		return (validate_path(ctx, cmd));
	last = OK;
	path = path_get_bin(env, cmd, &last);
	if (!path)
		return (path_error(last, cmd));
	ctx->cmd.path = path;
	return (0);
}
