/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:50:13 by Oery              #+#    #+#             */
/*   Updated: 2026/05/03 16:50:31 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include "libft.h"
# include "src/ctx/ctx.h"

enum	e_redir
{
	READ_IN,
	WRITE_OUT,
	HEREDOC,
	APPEND,
	NO_REDIR,
};

typedef struct s_cmd
{
	char	*path;
}			t_cmd;

typedef struct s_exec_io
{
	int					in;
	int					out;
}						t_exec_io;

typedef struct s_exec_pipe
{
	size_t				index;
	int					fd;
}						t_exec_pipe;


typedef struct	s_exec_ctx
{
	size_t				args_nb;
	enum e_redir		redir;
	struct s_cmd		cmd;
	struct s_exec_io	fd;
	struct s_exec_pipe	pipe;
}						t_exec_ctx;

bool				is_sq_string(t_string *s);
unsigned int		cmd_handle(const char *input, t_ctx *ctx);
void				cmd_quotes_remove(const t_array *words);

#endif
