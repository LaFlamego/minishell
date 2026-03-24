/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 21:05:59 by Oery              #+#    #+#             */
/*   Updated: 2026/03/24 17:35:58 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell/ctx.h"
# include <sys/types.h>

void			cmd_exec(t_ctx *ctx, t_array *args);
unsigned int	cmd_exec_bin(char *argv[], t_env *env);
pid_t			cmd_exec_fork(char *argv[], t_env *env);
char			*cmd_exec_get_path(char *cmd_name, t_env *env);

#endif
