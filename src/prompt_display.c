/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 13:15:33 by crevette          #+#    #+#             */
/*   Updated: 2026/03/11 00:03:30 by Oery             ###   ########.fr       */
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
	char	**args;
	int		argc;

	while (1)
	{
		input = readline("(=^.^=)$ ");
		args = ft_split(input, ' ');
		argc = 0;
		while (args[argc])
			argc++;
		if (input[0] == 'u')
			mini_unset(argc, args, ctx);
		else if (input[0] == 'e')
			mini_export(argc, args, ctx);
		free_splits(args);
		free(input);
	}
}
