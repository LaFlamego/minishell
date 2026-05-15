/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 22:01:11 by crevette          #+#    #+#             */
/*   Updated: 2026/05/15 16:26:43 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./expand.h"
#include <stdlib.h>
#include <unistd.h>

static int	handle_heredoc(t_word_part *part, t_exec_ctx *ctx)
{
	if (ctx->fd.in > 2)
		fd_close_reset(&ctx->fd.in, NULL, NULL);
	ctx->fd.heredoc = (int)(intptr_t)part->data;
	part->data = (void *)(intptr_t)-1;
	ctx->redir = HEREDOC;
	return (1);
}

static int	handle_file(t_word_part *part, t_exec_ctx *ctx)
{
	char	*arg;
	int		res;

	res = 1;
	arg = expand_target(part->data, ctx->env);
	if (!arg)
		return (1);
	if (part->kind == WK_REDIRECT_IN)
		res = redirect_in(arg, ctx);
	if (part->kind == WK_REDIRECT_OUT)
		res = redirect_out(arg, ctx);
	if (part->kind == WK_REDIRECT_OUT_APPEND)
		res = redirect_out_append(arg, ctx);
	free(arg);
	return (res);
}

int	expand_redirection(t_word_part *part, t_exec_ctx *ctx)
{
	if (part->kind == WK_REDIRECT_IN_UNTIL_FD)
		return (handle_heredoc(part, ctx));
	else
		return (handle_file(part, ctx));
}
