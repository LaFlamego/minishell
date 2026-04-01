/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 17:21:48 by crevette          #+#    #+#             */
/*   Updated: 2026/04/02 01:28:03 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "src/ctx/ctx.h"

unsigned int	mini_echo(int argc, char *argv[], t_ctx *ctx)
{
	int	i;

	(void)ctx;
	if (argc > 1)
	{
		i = 1 + ft_streq(argv[1], "-n");
		while (i < argc)
		{
			ft_printf("%s", argv[i]);
			if (i < argc - 1)
				ft_printf(" ");
			++i;
		}
	}
	if (argc == 1 || !ft_streq(argv[1], "-n"))
		ft_printf("\n");
	return (0);
}
