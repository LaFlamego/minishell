/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:06:22 by crevette          #+#    #+#             */
/*   Updated: 2026/03/13 18:49:48 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/printf.h"
#include "libft/string.h"
#include "minishell/ctx.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 64

static unsigned int	print_pwd(void)
{
	t_string	buf;

	if (!ft_string_alloc(&buf, BUFFER_SIZE))
		return (1);
	while (getcwd(buf.content, buf.capacity) == NULL && errno == ERANGE)
	{
		if (!ft_string_realloc(&buf, buf.capacity * 2))
			return (1);
	}
	if (errno && !buf.content)
	{
		ft_dprintf(2, "minishell: pwd: %s\n", strerror(errno));
		return (1);
	}
	ft_dprintf(1, "%s\n", buf.content);
	free(buf.content);
	return (0);
}

unsigned int	mini_pwd(int argc, char *argv[], t_ctx *ctx)
{
	unsigned int	exit_code;

	(void)argv;
	(void)ctx;
	(void)argc;
	exit_code = print_pwd();
	return (exit_code);
}
