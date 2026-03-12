/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 18:30:12 by Oery              #+#    #+#             */
/*   Updated: 2026/03/12 23:41:04 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <limits.h>

#define BASE 10

// TODO: Default Exit Code of mini_exit should be
// > the same as the one of the last executed command

static int	will_overflow(char c, long long n, long long sign)
{
	if (sign > 0)
	{
		if (n > LLONG_MAX / BASE || (n * BASE > LLONG_MAX - (c - '0')))
			return (1);
	}
	else
	{
		if (n < LLONG_MIN / BASE || (n * BASE) < LLONG_MIN + (c - '0'))
			return (1);
	}
	return (0);
}

static int	parse_arg(char *arg, long long *exit_code)
{
	size_t		i;
	long long	sign;

	*exit_code = 0;
	i = 0;
	sign = 1;
	if (arg[i] == '-' || arg[i] == '+')
	{
		if (arg[i] == '-')
			sign = -1;
		i++;
	}
	if (!arg[i])
		return (1);
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]) || will_overflow(arg[i], *exit_code, sign))
			return (1);
		*exit_code *= BASE;
		*exit_code += sign * (arg[i] - '0');
		i++;
	}
	return (0);
}

unsigned int	mini_exit(int argc, char *argv[], t_ctx *ctx)
{
	long long	exit_code;

	ft_printf("exit\n");
	if (argc > 2)
	{
		ft_dprintf(2, "minishell: exit: too many arguments\n");
		return (2);
	}
	if (argc > 1)
	{
		if (parse_arg(argv[1], &exit_code))
		{
			ft_dprintf(2, "minishell: exit: %s: numeric argument required\n",
				argv[1]);
			return (2);
		}
		ctx->exit = true;
		return ((unsigned int)(unsigned char)exit_code);
	}
	ctx->exit = true;
	return (0);
}
