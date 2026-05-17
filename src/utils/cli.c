/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 23:43:54 by Oery              #+#    #+#             */
/*   Updated: 2026/05/16 20:51:51 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.h"
#include "libft.h"
#include "src/ctx/ctx.h"

static int	error(enum e_cli_error e, char *arg)
{
	if (e == CLI_NOT_AN_OPTION)
		ft_dprintf(2, "minishell: %s: not an option\n", arg);
	if (e == CLI_MISSING_ARGUMENT)
		ft_dprintf(2, "minishell: %s: missing argument\n", arg);
	if (e == CLI_INVALID_OPTION)
		ft_dprintf(2, "minishell: %s: invalid option\n", arg);
	return (0);
}

static int	parse_arg(int *i, char **argv, t_ctx *ctx)
{
	if (!ft_startswith(argv[*i], "-"))
		return (error(CLI_NOT_AN_OPTION, argv[*i]));
	if (ft_streq(argv[*i], "-d"))
	{
		ctx->flags |= FLAG_DEBUG;
		return (1);
	}
	return (error(CLI_INVALID_OPTION, argv[*i]));
}

int	cli_parse_args(int argc, char **argv, t_ctx *ctx)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!parse_arg(&i, argv, ctx))
			return (0);
		i++;
	}
	return (1);
}
