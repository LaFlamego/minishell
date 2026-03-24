/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 13:15:33 by crevette          #+#    #+#             */
/*   Updated: 2026/03/24 17:20:33 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell/cmd.h"
#include "minishell/prompt.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdlib.h>

// TODO: Handle new lines

// FIXME: Ctrl+D should print exit
// > on the current command line
// > not the next one.
void	prompt_display(t_ctx *ctx)
{
	char	*input;

	while (!ctx->exit)
	{
		input = readline("(=^.^=)$ ");
		if (!input)
		{
			rl_replace_line("exit\n", 0);
			rl_on_new_line();
			rl_redisplay();
			return ;
		}
		if (*input == '\0')
		{
			free(input);
			continue ;
		}
		cmd_handle(input, ctx);
		// TODO: Check if input is good
		// > Empty Input should not be added to the history
		add_history(input);
		free(input);
	}
	rl_clear_history();
}
