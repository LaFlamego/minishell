/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 21:03:47 by Oery              #+#    #+#             */
/*   Updated: 2026/05/14 21:55:08 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "src/builtins/builtins.h"
#include "src/ctx/ctx.h"
#include "src/env/env.h"

static unsigned int (*get_builtin(char *cmd_name))(int, char **, t_ctx *)
{
	if (ft_streq(cmd_name, "echo"))
		return (&mini_echo);
	if (ft_streq(cmd_name, "cd"))
		return (&mini_cd);
	if (ft_streq(cmd_name, "env"))
		return (&mini_env);
	if (ft_streq(cmd_name, "export"))
		return (&mini_export);
	if (ft_streq(cmd_name, "pwd"))
		return (&mini_pwd);
	if (ft_streq(cmd_name, "unset"))
		return (&mini_unset);
	if (ft_streq(cmd_name, "exit"))
		return (&mini_exit);
	return (NULL);
}

unsigned int	cmd_exec(t_ctx *ctx, t_exec_ctx *exec, t_array *argv)
{
	unsigned int	exit_code;
	unsigned int	(*builtin)(int, char **, t_ctx *);

	builtin = get_builtin(argv->data[0]);
	if (builtin && exec->is_pipe == false)
	{
		redir_fd(exec, true);
		exit_code = builtin(argv->size - 1, (char **)argv->data, ctx);
		restore_stdio(exec);
	}
	else
		exit_code = cmd_exec_bin(argv, ctx->env, exec);
	env_set_exit_code(exit_code, ctx->env);
	return (exit_code);
}
