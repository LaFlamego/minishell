/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 15:03:31 by Oery              #+#    #+#             */
/*   Updated: 2026/05/15 16:01:40 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H

# include "./src/cmd/exec/exec.h"
# include "./src/env/env.h"
# include <stdbool.h>

typedef enum e_access_result
{
	OK,
	ERRNO,
	FILE_NOT_FOUND,
	ACCESS_DENIED,
	CMD_NOT_FOUND,
	IS_DIR,
}				t_path_res;

unsigned int	path_get_cmd(char *cmd, t_exec_ctx *ctx, t_env *env);
char			*path_get_bin(t_env *env, char *cmd, t_path_res *last);

// > Path Errors
unsigned int	path_error(t_path_res res, char *cmd);
bool			path_is_error(t_path_res res);

// > Access Checks
bool			file_exists(const char *path);
bool			has_exe_perm(const char *path);

#endif
