/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 18:30:12 by Oery              #+#    #+#             */
/*   Updated: 2026/03/12 21:24:03 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

// TODO: Default Exit Code of mini_exit should be
// > the same as the one of the last executed command

// NOTE: Argument is a byte
// > -1 should return 255

int	parse_arg(char *arg, unsigned int *exit_code)
{
	size_t	i;

	*exit_code = 0;
	i = 0;
	if (arg[i] == '-')
	{
		i++;
	}
	else if (arg[i] == '+')
	{
		if (!arg[i + 1])
			return (1);
		i++;
	}
	// TODO: Handle -/+ sign
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (1);
		*exit_code *= 10;
		*exit_code += arg[i] - '0';
		i++;
	}
	return (0);
}

unsigned int	mini_exit(int argc, char *argv[], t_ctx *ctx)
{
	unsigned int	exit_code;

	ft_printf("exit\n");
	if (argc > 2)
	{
		ft_dprintf(2, "exit: too many arguments\n");
		return (2);
	}
	if (argc > 1)
	{
		if (parse_arg(argv[1], &exit_code))
		{
			ft_dprintf(2, "exit: %s: numeric argument required\n", argv[1]);
			return (2);
		}
		ctx->exit = true;
		return (exit_code);
	}
	ctx->exit = true;
	return (0);
}
