/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 21:11:29 by crevette          #+#    #+#             */
/*   Updated: 2026/05/16 20:47:50 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "src/prompt/prompt.h"
#include "src/utils/utils.h"
#include <unistd.h>

static int	get_exit_code(t_ctx *ctx)
{
	char	*value;

	value = env_get(ctx->env, "?");
	if (!value)
		return (1);
	return (ft_atoi(value));
}

int	main(int argc, char *argv[], char *envp[])
{
	t_ctx			ctx;
	unsigned int	exit_code;

	if (!ctx_init(&ctx, envp))
	{
		ft_dprintf(2, "minishell: failed to initialize context\n");
		return (1);
	}
	if (!cli_parse_args(argc, argv, &ctx))
		return (1);
	prompt_display(&ctx);
	exit_code = get_exit_code(&ctx);
	ctx_free(&ctx);
	return (exit_code);
}
