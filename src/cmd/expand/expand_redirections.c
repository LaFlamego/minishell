/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 22:01:11 by crevette          #+#    #+#             */
/*   Updated: 2026/05/11 13:04:23 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec/exec.h"
#include "libft.h"
#include "src/utils/utils.h"
#include <fcntl.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
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
		perror("open");
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
		perror("open");
		return (0);
	}
	exec_ctx->fd.out = fd_file_to;
	exec_ctx->redir = WRITE_OUT;
	return (1);
}

// TODO: Maybe add a history line ehre
int	redirect_in_until(t_exec_ctx *exec_ctx, char *limiter)
{
	char	*new_line;
	size_t	len_limiter;
	int		fd_in;
	int		fd_out;

	if (exec_ctx->fd.in > 2)
		fd_close_reset(&exec_ctx->fd.in, NULL, NULL);
	len_limiter = ft_strlen(limiter);
	pipe_build(&fd_in, &fd_out);
	new_line = readline("> ");
	while (new_line != NULL)
	{
		if (len_limiter > 0 && ft_strncmp(new_line, limiter, len_limiter) == 0)
			break ;
		write(fd_out, new_line, ft_strlen(new_line));
		write(fd_out, "\n", 1);
		free(new_line);
		new_line = readline("> ");
	}
	free(new_line);
	fd_close_reset(NULL, &fd_out, NULL);
	exec_ctx->fd.in = fd_in;
	exec_ctx->redir = HEREDOC;
	return (1);
}

int	redirect_out_append(char *file_to, t_exec_ctx *exec_ctx)
{
	int	fd_file_to;

	if (exec_ctx->fd.out > 2)
		fd_close_reset(NULL, &exec_ctx->fd.out, NULL);
	fd_file_to = open(file_to, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd_file_to == -1)
	{
		perror("open");
		return (0);
	}
	exec_ctx->fd.out = fd_file_to;
	exec_ctx->redir = APPEND;
	return (1);
}
