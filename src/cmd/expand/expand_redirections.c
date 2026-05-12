/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 22:01:11 by crevette          #+#    #+#             */
/*   Updated: 2026/05/12 21:31:11 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec/exec.h"
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

// TODO: This should be done in the child for CTRL+C to work
int	redirect_in_until(char *del)
{
	char	*line;
	int		fd_in;
	int		fd_out;

	if (pipe_build(&fd_in, &fd_out))
		return (1);
	//dup2(ctx->shell->stdin, STDIN_FILENO);
	line = readline("> ");
	while (line != NULL && !ft_streq(line, del))
	{
		write(fd_out, line, ft_strlen(line));
		write(fd_out, "\n", 1);
		free(line);
		line = readline("> ");
	}
	free(line);
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
