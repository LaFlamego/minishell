/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 13:15:33 by crevette          #+#    #+#             */
/*   Updated: 2026/05/05 12:59:16 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./prompt.h"
#include "src/cmd/cmd.h"
#include "src/utils/utils.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdlib.h>

unsigned int	prompt_display(t_ctx *ctx)
{
	char	*input;

	while (!ctx->exit)
	{
		input = readline("(=^.^=)$ ");
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
		history_save(ctx->env, input);
		if (cmd_handle(input, ctx))
		{
			free(input);
			return (0);
		}
		free(input);
	}
	return (1);
}
