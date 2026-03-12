/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 12:18:23 by crevette          #+#    #+#             */
/*   Updated: 2026/03/09 20:56:13 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>

void	mini_cd(int argc, char **argv)
{
	size_t	size;	

	if (argc > 2)
		ft_fprintf("cd: too many arguments\n");
	else if (argv[1] && chdir(argv[1]) == -1)
		perror("cd");
	while (!getcwd(buf, size))
	{
		if (errno == ERANGE)
		{	
			size *= 2;
			buf = (char *)malloc(sizeof(char) * size);

		}
	} 
}
