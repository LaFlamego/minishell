/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 21:11:29 by crevette          #+#    #+#             */
/*   Updated: 2026/04/28 21:55:11 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "src/prompt/prompt.h"

// #include "minishell/signal.h"

// TODO: Maybe we should get the original $? from the current envp
// TODO: Initialize PWD to getcwd()
int	main(int argc, char *argv[], char *envp[])
{
	t_ctx	ctx;

	(void)argc;
	(void)argv;
	if (!ctx_init(&ctx, envp))
	{
		ft_dprintf(2, "minishell: failed to initialize context\n");
		return (1);
	};
	// set_sigactions();
	prompt_display(&ctx);
	env_free(ctx.env);
	return (0);
}
