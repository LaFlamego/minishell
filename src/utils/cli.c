/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 23:43:54 by Oery              #+#    #+#             */
/*   Updated: 2026/04/29 00:28:52 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "src/cmd/cmd.h"

static void	print_help_message(void)
{
	ft_printf("Usage:  minishell [option]\n");
	ft_printf("Shell options:\n");
	ft_printf("        -c command\n");
}

static void	handle_error(int argc, char **argv)
{
	if (argc > 1 && !ft_startswith(argv[1], "-"))
		ft_dprintf(2, "minishell: %s: not an option\n", argv[1]);
	else if (argc > 1 && !ft_streq(argv[1], "-c"))
		ft_dprintf(2, "minishell: %s: invalid option\n", argv[1]);
	else if (argc > 1 && argc < 3 && ft_streq(argv[1], "-c"))
		ft_dprintf(2, "minishell: not enough arguments\n");
	else if (argc > 3)
		ft_dprintf(2, "minishell: too many arguments\n");
	print_help_message();
}

int	handle_args(int argc, char **argv, t_ctx *ctx)
{
	if (argc != 3 || !ft_streq(argv[1], "-c"))
	{
		handle_error(argc, argv);
		return (2);
	}
	return (cmd_handle(argv[2], ctx));
}
