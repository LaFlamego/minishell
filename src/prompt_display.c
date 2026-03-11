/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 13:15:33 by crevette          #+#    #+#             */
/*   Updated: 2026/03/11 18:41:55 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdlib.h>

void	prompt_display(t_ctx *ctx)
{
	char	*input;
	char	**argv;
	int		argc;

	while (1)
	{
		input = readline("(=^.^=)$ ");
		argv = ft_split(input, ' ');
		argc = 0;
		while (argv[argc])
			argc++;
		if (ft_streq(argv[0], "unset"))
			mini_unset(argc, argv, ctx);
		else if (ft_streq(argv[0], "export"))
			mini_export(argc, argv, ctx);
		free_splits(argv);
		free(input);
	}
}
