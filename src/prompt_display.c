/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 13:15:33 by crevette          #+#    #+#             */
/*   Updated: 2026/03/12 23:59:55 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdlib.h>

// TODO: Handle new lines

// FIXME: Ctrl+D should print exit
// > on the current command line
// > not the next one.
void	prompt_display(t_ctx *ctx)
{
	char			*input;
	char			**argv;
	int				argc;
	unsigned int	exit_code;

	exit_code = 0;
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
		else if (ft_streq(argv[0], "env"))
			mini_env(argc, argv, ctx);
		else if (ft_streq(argv[0], "exit"))
		{
			exit_code = mini_exit(argc, argv, ctx);
		}
		printf("exit code: %u\n", exit_code);
		// TODO: Check if input is good
		add_history(input);
		free_splits(argv);
		free(input);
	}
	rl_clear_history();
}
