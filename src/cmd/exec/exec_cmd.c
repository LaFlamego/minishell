/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 21:03:47 by Oery              #+#    #+#             */
/*   Updated: 2026/05/15 17:18:39 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "src/builtins/builtins.h"
#include "src/ctx/ctx.h"
#include "src/env/env.h"

static bool	is_builtin(char *cmd)
{
	if (ft_streq(cmd, "echo") || ft_streq(cmd, "cd"))
		return (true);
	if (ft_streq(cmd, "env") || ft_streq(cmd, "export"))
		return (true);
	if (ft_streq(cmd, "pwd") || ft_streq(cmd, "unset"))
		return (true);
	if (ft_streq(cmd, "exit"))
		return (true);
	return (false);
}

static unsigned int	run_builtin(int argc, char **argv, t_ctx *ctx)
{
	if (ft_streq(argv[0], "echo"))
		return (mini_echo(argc, argv, ctx));
	if (ft_streq(argv[0], "cd"))
		return (mini_cd(argc, argv, ctx));
	if (ft_streq(argv[0], "env"))
		return (mini_env(argc, argv, ctx));
	if (ft_streq(argv[0], "export"))
		return (mini_export(argc, argv, ctx));
	if (ft_streq(argv[0], "pwd"))
		return (mini_pwd(argc, argv, ctx));
	if (ft_streq(argv[0], "unset"))
		return (mini_unset(argc, argv, ctx));
	if (ft_streq(argv[0], "exit"))
		return (mini_exit(argc, argv, ctx));
	return (1);
}

unsigned int	cmd_exec(t_ctx *ctx, t_exec_ctx *exec, t_array *argv)
{
	unsigned int	exit_code;

	if (is_builtin(argv->data[0]) && exec->is_pipe == false)
	{
		redir_fd(exec, true);
		exit_code = run_builtin(argv->size - 1, (char **)argv->data, ctx);
		restore_stdio(exec);
	}
	else
		exit_code = cmd_exec_bin(argv, ctx->env, exec);
	env_set_exit_code(exit_code, ctx->env);
	return (exit_code);
}
