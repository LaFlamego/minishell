/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 17:21:48 by crevette          #+#    #+#             */
/*   Updated: 2026/05/16 22:30:14 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "src/ctx/ctx.h"

unsigned int	mini_echo(int argc, char *argv[], t_ctx *ctx)
{
	int		i;
	bool	new_line;

	(void)ctx;
	new_line = true;
	i = 1;
	while (i < argc && ft_streq(argv[i], "-n"))
	{
		new_line = false;
		i++;
	}
	while (i < argc)
	{
		ft_printf("%s", argv[i]);
		if (i < argc - 1)
			ft_printf(" ");
		i++;
	}
	if (argc == 1 || new_line)
		ft_printf("\n");
	return (0);
}
