/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 23:43:54 by Oery              #+#    #+#             */
/*   Updated: 2026/04/30 18:53:11 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "src/ctx/ctx.h"

enum		e_cli_error
{
	CLI_MISSING_ARGUMENT,
	CLI_INVALID_OPTION,
	CLI_NOT_AN_OPTION,
};

static void	print_help_message(void)
{
	ft_printf("Usage:  minishell [option]\n");
	ft_printf("Shell options:\n");
	ft_printf("        -c command\n");
	ft_printf("        -d\n");
}

static int	error(enum e_cli_error e, char *arg)
{
	if (e == CLI_NOT_AN_OPTION)
		ft_dprintf(2, "minishell: %s: not an option\n", arg);
	if (e == CLI_MISSING_ARGUMENT)
		ft_dprintf(2, "minishell: %s: missing argument\n", arg);
	if (e == CLI_INVALID_OPTION)
		ft_dprintf(2, "minishell: %s: invalid option\n", arg);
	print_help_message();
	return (0);
}

static int	parse_arg(int *i, int argc, char **argv, t_ctx *ctx)
{
	if (!ft_startswith(argv[*i], "-"))
		return (error(CLI_NOT_AN_OPTION, argv[*i]));
	if (ft_streq(argv[*i], "-c"))
	{
		ctx->flags |= FLAG_CLI_MODE;
		if (argc <= *i + 1)
			return (error(CLI_MISSING_ARGUMENT, argv[*i]));
		ctx->command = argv[*i + 1];
		(*i)++;
		return (1);
	}
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
		if (!parse_arg(&i, argc, argv, ctx))
			return (0);
		i++;
	}
	return (1);
}
