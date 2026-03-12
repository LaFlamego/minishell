/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 13:15:33 by crevette          #+#    #+#             */
/*   Updated: 2026/03/12 15:13:14 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdlib.h>

// FIXME: Ctrl+D should print exit
// > on the current command line
// > not the next one.
void	prompt_display(t_ctx *ctx)
{
	char	*input;
	char	**argv;
	int		argc;

	while (!ctx->exit)
	{
		input = readline("(=^.^=)$ ");
		if (!input)
		{
			rl_replace_line("exit\n", 0);
			rl_on_new_line();
			rl_redisplay();
			return ;
		}
		argv = ft_split(input, ' ');
		argc = 0;
		while (argv[argc])
			argc++;
		if (ft_streq(argv[0], "unset"))
			mini_unset(argc, argv, ctx);
		else if (ft_streq(argv[0], "export"))
			mini_export(argc, argv, ctx);
		else if (ft_streq(argv[0], "exit"))
			mini_exit(ctx);
		free_splits(argv);
		free(input);
	}
}
