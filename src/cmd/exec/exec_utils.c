/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:37:56 by crevette          #+#    #+#             */
/*   Updated: 2026/05/15 19:48:04 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "libft.h"
#include "src/cmd/tree/word/word.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

unsigned int	pipe_build(int *pipe_in, int *pipe_out)
{
	int	pipefd[2];

	if (pipe(pipefd) == -1)
	{
		perror("minishell: pipe");
		return (1);
	}
	*pipe_in = pipefd[0];
	*pipe_out = pipefd[1];
	return (0);
}

void	close_heredocs_in_words(t_word *words)
{
	t_word		*word;
	t_list		*parts;
	t_word_part	*part;
	int			fd;

	word = words;
	while (word)
	{
		parts = word->content;
		while (parts)
		{
			part = parts->content;
			if (part && part->kind == WK_REDIRECT_IN_UNTIL_FD)
			{
				fd = (int)(intptr_t)part->data;
				if (fd >= 0)
				{
					close(fd);
					part->data = (void *)(intptr_t) - 1;
				}
			}
			parts = parts->next;
		}
		word = word->next;
	}
}

void	close_other_heredocs(t_list *head, t_cmd_node *current)
{
	t_list		*node;
	t_cmd_node	*cmd;

	node = head;
	while (node)
	{
		cmd = node->content;
		if (cmd && cmd != current && cmd->kind == COMMAND)
			close_heredocs_in_words(cmd->data);
		node = node->next;
	}
}

void	fd_close_reset(int *pipein, int *pipeout, int *prevfd)
{
	if (pipein && *pipein >= 0)
	{
		close(*pipein);
		*pipein = -1;
	}
	if (pipeout && *pipeout >= 0)
	{
		close(*pipeout);
		*pipeout = -1;
	}
	if (prevfd && *prevfd >= 0)
	{
		close(*prevfd);
		*prevfd = -1;
	}
}

void	free_cmd_path(t_exec_ctx *exec)
{
	if (exec->cmd.path == NULL)
		return ;
	free(exec->cmd.path);
	exec->cmd.path = NULL;
}
