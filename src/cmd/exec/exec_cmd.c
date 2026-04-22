/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 21:03:47 by Oery              #+#    #+#             */
/*   Updated: 2026/04/22 16:43:26 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./exec.h"
#include "src/builtins/builtins.h"
#include "src/ctx/ctx.h"
#include "src/env/env.h"

static char	**get_argv(t_array *argv, t_array *words)
{
	size_t		i;
	t_string	*word;

	ft_bzero(argv, sizeof(t_array));
	i = 0;
	while (i < words->size)
	{
		word = words->data[i];
		ft_array_push(argv, word->content);
		i++;
	}
	return ((char **)argv->data);
}

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

unsigned int	cmd_exec(t_ctx *ctx, t_array *args)
{
	unsigned int	exit_code;
	unsigned int	(*builtin)(int, char **, t_ctx *);
	t_array			argv;

	get_argv(&argv, args);
	builtin = get_builtin(argv.data[0]);
	if (builtin)
	{
		exit_code = builtin((int)argv.size, (char **)argv.data, ctx);
	}
	else
	{
		ft_array_push(&argv, NULL);
		exit_code = cmd_exec_bin((char **)argv.data, ctx->env);
	}
	env_set_exit_code(exit_code, ctx->env);
	return (exit_code);
}
