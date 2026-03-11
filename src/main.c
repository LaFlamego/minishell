/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 21:11:29 by crevette          #+#    #+#             */
/*   Updated: 2026/03/11 19:04:15 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_ctx	ctx;

	(void)argc;
	(void)argv;
	ctx.env = ft_env_from(envp);
	ctx.exit = false;
	if (!ctx.env)
		return (1);
	prompt_display(&ctx);
	ft_env_free(ctx.env);
	return (0);
}
