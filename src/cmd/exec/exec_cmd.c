/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 21:03:47 by Oery              #+#    #+#             */
/*   Updated: 2026/05/04 18:28:07 by crevette         ###   ########.fr       */
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

unsigned int	cmd_exec(t_ctx *ctx, t_exec_ctx *exec, char *argv[])
{
	unsigned int	exit_code;
	unsigned int	(*builtin)(int, char **, t_ctx *);
	int				argc;

	builtin = get_builtin(argv[0]);
	argc = 0;
	while (argv[argc])
		argc++;
	if (builtin)
		exit_code = builtin(argc, argv, ctx);
	else
	{
		ft_array_push(&argv, NULL);
		exit_code = cmd_exec_bin(argv, ctx->env, exec);
	}
	env_set_exit_code(exit_code, ctx->env);
	return (exit_code);
}
