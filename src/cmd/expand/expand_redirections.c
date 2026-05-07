/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 22:01:11 by crevette          #+#    #+#             */
/*   Updated: 2026/05/07 22:33:22 by Oery             ###   ########.fr       */
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

// TODO: How to handle errors here?

void	redirect_in(char *file_to, t_exec_ctx *exec_ctx)
{
	int	fd_file_to;

	fd_file_to = open(file_to, O_RDONLY);
	if (fd_file_to == -1)
	{
		perror("open");
		return ;
	}
	exec_ctx->fd.in = fd_file_to;
	exec_ctx->redir = READ_IN;
}

void	redirect_out(char *file_to, t_exec_ctx *exec_ctx)
{
	int	fd_file_to;

	fd_file_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_file_to == -1)
	{
		perror("open");
		return ;
	}
	exec_ctx->fd.out = fd_file_to;
	exec_ctx->redir = WRITE_OUT;
}

// TODO: Maybe add a history line ehre
void	redirect_in_until(t_exec_ctx *exec_ctx, char *limiter)
{
	char	*new_line;
	size_t	len_limiter;
	int		fd_in;
	int		fd_out;

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
}

void	redirect_out_append(char *file_to, t_exec_ctx *exec_ctx)
{
	int	fd_file_to;

	fd_file_to = open(file_to, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd_file_to == -1)
	{
		perror("open");
		return ;
	}
	exec_ctx->fd.out = fd_file_to;
	exec_ctx->redir = APPEND;
}
