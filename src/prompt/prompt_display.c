/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 13:15:33 by crevette          #+#    #+#             */
/*   Updated: 2026/05/18 12:44:42 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./prompt.h"
#include "src/cmd/cmd.h"
#include "src/utils/utils.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>
#include <stdlib.h>

static int	readline_signal_hook(void)
{
	if (g_signal == SIGINT)
	{
		ft_printf("%s%s^C", rl_prompt, rl_line_buffer);
		rl_done = 1;
	}
	if (g_signal == SIGQUIT)
	{
		g_signal = 0;
		rl_redisplay();
	}
	return (0);
}

static int	handle_input(t_ctx *ctx, char *input)
{
	if (!input)
	{
		ft_printf("exit\n");
		return (1);
	}
	add_history(input);
	if (cmd_handle(input, ctx))
	{
		free(input);
		return (1);
	}
	free(input);
	return (0);
}

static bool	is_empty(char *line)
{
	size_t	i;

	i = 0;
	while (line && line[i])
	{
		if (!ft_isspace(line[i]))
			return (false);
		i++;
	}
	return (true);
}

unsigned int	prompt_display(t_ctx *ctx)
{
	char	*input;

	rl_event_hook = readline_signal_hook;
	while (!ctx->exit)
	{
		g_signal = 0;
		input = readline("(=^.^=)$ ");
		if (g_signal == SIGQUIT || g_signal == SIGINT || is_empty(input))
		{
			free(input);
			continue ;
		}
		if (handle_input(ctx, input))
			return (1);
	}
	return (1);
}
