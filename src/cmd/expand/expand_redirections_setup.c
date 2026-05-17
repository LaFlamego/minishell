/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_redirections_setup.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 16:22:55 by Oery              #+#    #+#             */
/*   Updated: 2026/05/18 00:49:22 by Oery             ###   ########.fr       */
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

// FIXME: Handle error cases
static t_string	*handle_var(t_string *s, char *line, size_t *i, t_env *env)
{
	t_string	*key;

	*i += 1;
	key = ft_string_new(0);
	if (!key)
		return (NULL);
	if (ft_isdigit(line[*i]) || line[*i] == '?' || line[*i] == '$')
	{
		ft_string_push(key, line[*i]);
		ft_string_push_str(s, env_get(env, key->content));
		ft_string_free(key);
		return (s);
	}
	if (ft_isalpha(line[*i]) || line[*i] == '_')
	{
		while (ft_isalnum(line[*i]) || line[*i] == '_')
		{
			ft_string_push(key, line[*i]);
			*i += 1;
		}
		ft_string_push_str(s, env_get(env, key->content));
		ft_string_free(key);
		*i -= 1;
		return (s);
	}
	ft_string_push(s, '$');
	ft_string_free(key);
	*i -= 1;
	return (s);
}

static char	*expand_heredoc_input(char *line, t_env *env)
{
	t_string	*expanded;
	size_t		i;

	expanded = ft_string_new(0);
	if (!expanded)
		return (NULL);
	i = 0;
	while (line && line[i])
	{
		if (line[i] != '$' && !ft_string_push(expanded, line[i]))
		{
			ft_string_free(expanded);
			return (NULL);
		}
		if (line[i] == '$')
		{
			handle_var(expanded, line, &i, env);
		}
		i++;
	}
	return (ft_string_take(expanded));
}

static int	read_heredoc_input(int in, int out, const char *del, t_env *env)
{
	char	*line;
	char	*expanded;

	while (1)
	{
		g_signal = 0;
		line = readline("> ");
		if (g_signal == SIGINT)
		{
			close(in);
			close(out);
			return (0);
		}
		if (!line || ft_streq(line, del))
			break ;
		expanded = expand_heredoc_input(line, env);
		if (!expanded)
		{
			free(line);
			close(in);
			close(out);
			return (1);
		}
		ft_dprintf(out, "%s\n", expanded);
		free(line);
		free(expanded);
	}
	return (1);
}

int	redirect_in_until(char *del, t_env *env)
{
	int	fd_in;
	int	fd_out;

	if (pipe_build(&fd_in, &fd_out))
		return (-1);
	if (!read_heredoc_input(fd_in, fd_out, del, env))
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
