/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_redirections_setup.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 16:22:55 by Oery              #+#    #+#             */
/*   Updated: 2026/05/18 13:03:44 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec/exec.h"
#include "./expand.h"
#include "libft.h"
#include "src/utils/utils.h"
#include <errno.h>
#include <fcntl.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <stdlib.h>
#include <unistd.h>

int	redirect_in(char *file_to, t_exec_ctx *exec_ctx)
{
	int	fd_file_to;

	if (exec_ctx->fd.in > 2)
		fd_close_reset(&exec_ctx->fd.in, NULL, NULL);
	fd_file_to = open(file_to, O_RDONLY);
	if (fd_file_to == -1)
	{
		ft_dprintf(2, "minishell: %s: %s\n", file_to, strerror(errno));
		return (0);
	}
	exec_ctx->fd.in = fd_file_to;
	exec_ctx->redir = READ_IN;
	return (1);
}

int	redirect_out(char *file_to, t_exec_ctx *exec_ctx)
{
	int	fd_file_to;

	if (exec_ctx->fd.out > 2)
		fd_close_reset(NULL, &exec_ctx->fd.out, NULL);
	fd_file_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_file_to == -1)
	{
		ft_dprintf(2, "minishell: %s: %s\n", file_to, strerror(errno));
		return (0);
	}
	exec_ctx->fd.out = fd_file_to;
	exec_ctx->redir = WRITE_OUT;
	return (1);
}

static int	read_heredoc_input(int in, int out, const char *del)
{
	char	*line;

	while (1)
	{
		g_signal = 0;
		line = readline("> ");
		if (g_signal == SIGINT)
		{
			free(line);
			close(in);
			close(out);
			return (0);
		}
		if (!line || ft_streq(line, del))
			break ;
		ft_dprintf(out, "%s\n", line);
		free(line);
	}
	return (1);
}

int	redirect_in_until(char *del)
{
	int	fd_in;
	int	fd_out;

	if (pipe_build(&fd_in, &fd_out))
		return (-1);
	if (!read_heredoc_input(fd_in, fd_out, del))
		return (-1);
	fd_close_reset(NULL, &fd_out, NULL);
	return (fd_in);
}

int	redirect_out_append(char *file_to, t_exec_ctx *exec_ctx)
{
	int	fd_file_to;

	if (exec_ctx->fd.out > 2)
		fd_close_reset(NULL, &exec_ctx->fd.out, NULL);
	fd_file_to = open(file_to, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd_file_to == -1)
	{
		ft_dprintf(2, "minishell: %s: %s\n", file_to, strerror(errno));
		return (0);
	}
	exec_ctx->fd.out = fd_file_to;
	exec_ctx->redir = APPEND;
	return (1);
}
