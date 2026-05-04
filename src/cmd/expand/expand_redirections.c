/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 22:01:11 by crevette          #+#    #+#             */
/*   Updated: 2026/05/04 20:27:01 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec/exec.h"
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

void	fd_close_reset(int *pipein, int *pipeout, int *prevfd);

void	redirect_in(char *file_to, t_exec_ctx *exec_ctx)
{
	int	fd_file_to;

	fd_file_to = open(file_to, O_RDONLY);
	if (fd_file_to == -1)
		return (perror("open"));
	exec_ctx->fd.in = fd_file_to;
	exec_ctx->redir = READ_IN;
}

int	redirect_out(char *file_to, t_exec_ctx *exec_ctx)
{
	int	fd_file_to;

	fd_file_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_file_to == -1)
		return (perror("open"));
	exec_ctx->fd.out = fd_file_to;
	exec_ctx->redir = WRITE_OUT;
}

int	redirect_in_until(t_exec_ctx *exec_ctx, char *limiter)
{
	char	*new_line;
	size_t	len_limiter;
	int		fd_in;
	int		fd_out;

	len_limiter = ft_strlen(limiter);
	pipe_build(&fd_in, &fd_out);
	new_line = get_next_line(0);
	while (new_line != NULL)
	{
		if (len_limiter > 0 && ft_strncmp(new_line, limiter, len_limiter) == 0)
		{
			free(new_line);
			break ;
		}
		else
			write(fd_out, new_line, ft_strlen(new_line));
		free(new_line);
		new_line = get_next_line(0);
	}
	fd_close_reset(NULL, fd_out, NULL);
	exec_ctx->fd.in = fd_in;
	exec_ctx->redir = HEREDOC;
}

int	redirect_out_append(char *file_to, t_exec_ctx *exec_ctx)
{
	int	fd_file_to;

	fd_file_to = open(file_to, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd_file_to == -1)
		return (perror("open"));
	exec_ctx->fd.out = fd_file_to;
	exec_ctx->redir = APPEND;
}

