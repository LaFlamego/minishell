/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 21:11:29 by crevette          #+#    #+#             */
/*   Updated: 2026/03/22 22:17:25 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/prompt.h"
#include "minishell/signal.h"

// TODO: Maybe we should get the original $? from the current envp
// TODO: Initialize PWD to getcwd()
int	main(int argc, char *argv[], char *envp[])
{
	t_ctx	ctx;

	(void)argc;
	(void)argv;
	ctx_init(&ctx, envp);
	if (!ctx.env)
		return (1);
	set_sigactions();
	prompt_display(&ctx);
	ft_env_free(ctx.env);
	return (0);
}
