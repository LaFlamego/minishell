/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 21:11:29 by crevette          #+#    #+#             */
/*   Updated: 2026/05/03 10:43:44 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "src/cmd/cmd.h"
#include "src/prompt/prompt.h"
#include "src/utils/utils.h"

// TODO: What happens when we send the signal to stop the current job
// when a bultin command is running

// TODO: What is main's exit code?

int	main(int argc, char *argv[], char *envp[])
{
	t_ctx			ctx;
	unsigned int	exit_code;

	if (!ctx_init(&ctx, envp))
	{
		ft_dprintf(2, "minishell: failed to initialize context\n");
		return (1);
	};
	if (!cli_parse_args(argc, argv, &ctx))
		return (1);
	if (ctx.flags & FLAG_CLI_MODE)
		exit_code = cmd_handle(ctx.command, &ctx);
	else
		exit_code = prompt_display(&ctx);
	ctx_free(&ctx);
	return (exit_code);
}
