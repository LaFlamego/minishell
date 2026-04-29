/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:50:13 by Oery              #+#    #+#             */
/*   Updated: 2026/04/29 22:25:53 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include "libft.h"
# include "src/ctx/ctx.h"

typedef struct s_cmd
{
	char	*path;
	char	**cmds;
	//int				nb;
	//bool			is_path;
}			t_cmd;

typedef struct s_exec_pipe
{
	int				in;
	int				out;
	size_t			index;
}				t_exec_pipe;

typedef struct	s_exec_ctx
{
	size_t				args_nb;
	int					prev_fd;
	bool				is_pipe_cmd;
	struct s_exec_pipe	pipe;
}				t_exec_ctx;

bool				is_sq_string(t_string *s);
unsigned int		cmd_handle(const char *input, t_ctx *ctx);
void				cmd_quotes_remove(const t_array *words);

#endif
