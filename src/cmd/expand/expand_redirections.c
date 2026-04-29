/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 22:01:11 by crevette          #+#    #+#             */
/*   Updated: 2026/04/29 15:12:55 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cmd.h"
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

void	pipe_build(t_fds *fd);
void	fd_close_reset(int *pipein, int *pipeout, int *prevfd);
//TODO echo 123 < infile hello | cmd1
//TODO < infile

int	redirect_in(char *file_to)
{
	int	fd_file_to;
	int	dup;

	dup = -1;
	fd_file_to = open(file_to, O_RDONLY);
	if (fd_file_to == -1)
		return (perror("open"));
	else
		dup = dup2(fd_file_to, STDIN_FILENO);
	if (dup == -1)
		return (close(fd_file_to), perror("dup"));
	return (dup);
}

int	redirect_out(char *file_to)
{
	int	fd_file_to;
	int	dup;

	dup = -1;
	fd_file_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_file_to == -1)
		return (perror("open"));
	else
		dup = dup2(fd_file_to, STDOUT_FILENO);
	if (dup == -1)
		return (close(fd_file_to), perror("dup"));
	return (dup);
}

int	redirect_in_until(t_fds *fd, char *limiter)
{
	char	*new_line;
	size_t	len_limiter;
	int		dup;

	len_limiter = ft_strlen(limiter);
	pipe_build(fd);
	new_line = get_next_line(0);
	while (new_line != NULL)
	{
		if (len_limiter > 0 && ft_strncmp(new_line, limiter, len_limiter) == 0)
		{
			free(new_line);
			break ;
		}
		else
			write(fd->pipe_out, new_line, ft_strlen(new_line));
		free(new_line);
		new_line = get_next_line(0);
	}
	fd_close_reset(NULL, fd->pipe_out, NULL);
	dup = dup2(fd->pipe_in, STDIN_FILENO);
	if ( dup == -1)
		return(close(fd->pipe_in), perror("dup"));
	return (dup);
}

int	redirect_out_append(char *file_to)
{
	int	fd_file_to;
	int	dup;

	dup = -1;
	fd_file_to = open(file_to, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd_file_to == -1)
		return (perror("open"));
	else
		dup = dup2(fd_file_to, STDOUT_FILENO);
	if (dup == -1)
		return (close(fd_file_to), perror("dup"));
	return (dup);
}

