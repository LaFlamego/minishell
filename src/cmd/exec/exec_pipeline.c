/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 15:35:32 by crevette          #+#    #+#             */
/*   Updated: 2026/05/13 19:23:11 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "libft.h"
#include "src/cmd/tree/word/word.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

static void	close_heredocs_in_words(t_word *words)
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
					part->data = (void *)(intptr_t)-1;
				}
			}
			parts = parts->next;
		}
		word = word->next;
	}
}

static void	close_other_heredocs(t_list *head, t_cmd_node *current)
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

static void	pipeline_dup(t_exec_ctx *exec_ctx, int fd_dup, bool is_pipe_in)
{
	int	dup;

	dup = -1;
	if (is_pipe_in)
		dup = dup2(fd_dup, STDIN_FILENO);
	else
		dup = dup2(fd_dup, STDOUT_FILENO);
	if (dup == -1)
	{
		fd_close_reset(&exec_ctx->fd.in, &exec_ctx->fd.out, &exec_ctx->pipe.fd);
		perror("minishell: dup");
		return ;
	}
	// if (is_pipe_in)
	// 	fd_close_reset(&exec_ctx->fd.in, NULL, NULL);
	// else
	// 	fd_close_reset(NULL, &exec_ctx->fd.out, NULL);
}

static void	fd_proceed(t_exec_ctx *exec_ctx)
{
	int	in_fd;
	int	out_fd;

	if (exec_ctx->pipe.index == 1 && exec_ctx->pipe.fd == -1)
	{
		if (exec_ctx->fd.heredoc != -1)
			exec_ctx->pipe.fd = exec_ctx->fd.heredoc;
		else
			exec_ctx->pipe.fd = exec_ctx->fd.in;
	}
	in_fd = exec_ctx->pipe.fd;
	out_fd = exec_ctx->fd.out;
	if (in_fd != -1 && exec_ctx->pipe.index != 1)
		pipeline_dup(exec_ctx, in_fd, true);
	if (out_fd != -1 && exec_ctx->pipe.index != exec_ctx->args_nb)
		pipeline_dup(exec_ctx, out_fd, false);
	if (exec_ctx->pipe.index != 1 && exec_ctx->fd.heredoc != -1)
		fd_close_reset(NULL, NULL, &exec_ctx->fd.heredoc);
	fd_close_reset(&exec_ctx->fd.in, &exec_ctx->fd.out, &exec_ctx->pipe.fd);
}

pid_t	exec_pipeline(t_list *list, t_list *head, t_exec_ctx *exec_ctx,
		t_ctx *ctx)
{
	pid_t	pid;

	pid = -1;
	if (exec_ctx->pipe.index != exec_ctx->args_nb)
	{
		if (pipe_build(&exec_ctx->fd.in, &exec_ctx->fd.out) == 1)
			return (1);
	}
	pid = fork();
	if (pid < 0)
	{
		fd_close_reset(&exec_ctx->fd.in, &exec_ctx->fd.out, &exec_ctx->pipe.fd);
		fd_close_reset(NULL, NULL, &exec_ctx->fd.heredoc);
		return (perror("minishell: pid"), pid);
	}
	if (pid == 0)
	{
		close_other_heredocs(head, list->content);
		fd_proceed(exec_ctx);
		track_node(list->content, ctx);
		exit(pid);
	}
	if (pid > 0)
	{
		fd_close_reset(NULL, &exec_ctx->fd.out, NULL);
		if (exec_ctx->pipe.fd != -1)
			fd_close_reset(NULL, NULL, &exec_ctx->pipe.fd);
		if (exec_ctx->fd.heredoc != -1)
			fd_close_reset(NULL, NULL, &exec_ctx->fd.heredoc);
		exec_ctx->pipe.fd = exec_ctx->fd.in;
	}
	return (pid);
}
