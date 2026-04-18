/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 21:05:59 by Oery              #+#    #+#             */
/*   Updated: 2026/04/18 15:47:11 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "src/ctx/ctx.h"
# include <sys/types.h>
# include "../cmd.h"

void			cmd_exec(t_ctx *ctx, t_array *args);
unsigned int	cmd_exec_bin(char *argv[], t_env *env);
pid_t			cmd_exec_fork(char *argv[], t_env *env);
char			*cmd_exec_get_path(char *cmd_name, t_cmd *cmd, t_env *env);

#endif
