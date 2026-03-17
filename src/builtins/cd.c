/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 12:18:23 by crevette          #+#    #+#             */
/*   Updated: 2026/03/17 16:29:06 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishell/ctx.h"
#include "libft/string.h"
#include "libft/printf.h"
#include "libft.h"
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

#define BUFFER_SIZE 64

unsigned int update_cwd(char *key, t_ctx *ctx)
{
	t_string buf;
	int key_len;

	buf = ft_string_from_cstring_alloc(key);
	if (!buf.content)
		return (1);
	key_len = ft_strlen(key);
	while (getcwd(buf.content + key_len, buf.capacity - key_len) == NULL && errno == ERANGE)
	{
		if (!ft_string_realloc(&buf, buf.capacity * 2))
			return (free(buf.content), 1);
	}
	if (errno && !buf.content)
		return (free(buf.content), 1);
	else
	{
		ft_env_set(ctx->env, buf.content);
		free(buf.content);
	}
	return (0);
}

unsigned int mini_cd(int argc, char *argv[], t_ctx *ctx)
{

	if (argc > 2)
		ft_printf("minishell: cd: too many arguments\n");
	else if (argc < 2)
		ft_printf("minishell: cd: too few arguments\n");
	if (argc == 2)
	{
		if (argv[1] && argv[1][0])
		{
			if (update_cwd("OLDPWD=", ctx) == 1)
				return (1);
		}
		if (argv[1] && chdir(argv[1]) == -1)
			return (perror("cd"), 1);
		else
		{
			if (update_cwd("PWD=", ctx) == 1)
				return (1);
		}
		return (0);
	}
	return (1);
}
