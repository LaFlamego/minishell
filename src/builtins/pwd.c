/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:06:22 by crevette          #+#    #+#             */
/*   Updated: 2026/03/22 19:04:33 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell/ctx.h"
#include <errno.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 64

static unsigned int	print_pwd(void)
{
	t_string	*buf;

	buf = ft_string_new(BUFFER_SIZE);
	if (!buf)
		return (1);
	while (getcwd(buf->content, buf->capacity) == NULL && errno == ERANGE)
	{
		if (!ft_string_realloc(buf, buf->capacity * 2))
			return (1);
	}
	if (errno && !buf->content)
	{
		ft_dprintf(2, "minishell: pwd: %s\n", strerror(errno));
		return (1);
	}
	ft_dprintf(1, "%s\n", buf->content);
	ft_string_free(buf);
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
