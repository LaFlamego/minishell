/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:10:18 by crevette          #+#    #+#             */
/*   Updated: 2026/03/17 16:35:55 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishell/ctx.h"
#include "libft.h"
#include "minishell/builtins.h"

int	update_exit_code(unsigned int exit_code, t_ctx *ctx);

unsigned int (*get_builtin(char *cmd_name))(int, char **, t_ctx *)
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

void	cmd_run(char **cmds, t_ctx *ctx, int argc, char **argv)
{
	unsigned int	exit_code;
	unsigned int (*builtin)(int, char **, t_ctx *); 

	builtin = get_builtin(cmds[0]);
	if (builtin)
		exit_code = builtin(argc, argv, ctx);
	else
		exit_code = run_cmd(cmds, ctx->env);
	update_exit_code(exit_code, ctx);
}
