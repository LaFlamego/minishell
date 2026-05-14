/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 13:15:33 by crevette          #+#    #+#             */
/*   Updated: 2026/05/13 18:13:51 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./prompt.h"
#include "src/cmd/cmd.h"
#include "src/utils/utils.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>
#include <stdlib.h>

int	readline_signal_hook(void)
{
	if (g_signal == SIGINT)
	{
		rl_done = 1;
	}
	return (0);
}

unsigned int	prompt_display(t_ctx *ctx)
{
	char	*input;

	rl_event_hook = readline_signal_hook;
	while (!ctx->exit)
	{
		g_signal = 0;
		input = readline("(=^.^=)$ ");
		if (g_signal == SIGINT)
		{
			free(input);
			continue ;
		}
		if (!input)
		{
			ft_printf("exit\n");
			return (1);
		}
		if (*input == '\0')
		{
			free(input);
			continue ;
		}
		add_history(input);
		if (cmd_handle(input, ctx))
		{
			free(input);
			return (0);
		}
		free(input);
	}
	return (1);
}
