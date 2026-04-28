/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 13:15:33 by crevette          #+#    #+#             */
/*   Updated: 2026/04/28 22:30:41 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./prompt.h"
#include "src/cmd/cmd.h"
#include "src/utils/utils.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdlib.h>

void	prompt_display(t_ctx *ctx)
{
	char	*input;

	while (!ctx->exit)
	{
		input = readline("(=^.^=)$ ");
		if (!input)
		{
			ft_printf("exit\n");
			return ;
		}
		if (*input == '\0')
		{
			free(input);
			continue ;
		}
		cmd_handle(input, ctx);
		history_save(ctx->env, input);
		free(input);
	}
	rl_clear_history();
}
