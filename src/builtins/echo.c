/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 17:21:48 by crevette          #+#    #+#             */
/*   Updated: 2026/03/08 22:46:25 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mini_echo(int argc, char **argv)
{
	int i;

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
}
    
