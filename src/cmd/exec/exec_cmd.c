/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 21:03:47 by Oery              #+#    #+#             */
/*   Updated: 2026/03/22 22:05:17 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/builtins.h"
#include "minishell/ctx.h"
#include "minishell/env.h"
#include "minishell/exec.h"

static unsigned int (*get_builtin(char *cmd_name))(int, char **, t_ctx *)
{
	if (ft_streq(cmd_name, "echo"))
		return (&mini_echo);
	else if (ft_streq(cmd_name, "cd"))
		return (&mini_cd);
	else if (ft_streq(cmd_name, "env"))
		return (&mini_env);
	else if (ft_streq(cmd_name, "export"))
		return (&mini_export);
	else if (ft_streq(cmd_name, "pwd"))
		return (&mini_pwd);
	else if (ft_streq(cmd_name, "unset"))
		return (&mini_unset);
	else if (ft_streq(cmd_name, "exit"))
		return (&mini_exit);
	else
		return (NULL);
}

void	cmd_exec(t_ctx *ctx, int argc, char **argv)
{
	unsigned int	exit_code;
	unsigned int	(*builtin)(int, char **, t_ctx *);

	builtin = get_builtin(argv[0]);
	ft_printf("Builting = %p\n", builtin);
	if (builtin)
		exit_code = builtin(argc, argv, ctx);
	else
		exit_code = cmd_exec_bin(argv, ctx->env);
	ft_env_set_exit_code(exit_code, ctx->env);
}
