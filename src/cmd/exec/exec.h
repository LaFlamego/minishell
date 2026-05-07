/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 21:05:59 by Oery              #+#    #+#             */
/*   Updated: 2026/05/07 20:44:45 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "src/ctx/ctx.h"
# include <sys/types.h>
# include "../tree/node.h" 
# include "../cmd.h"

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
	bool				is_pipe;
	enum e_redir		redir;
	struct s_cmd		cmd;
	struct s_exec_io	fd;
	struct s_exec_pipe	pipe;
}						t_exec_ctx;

unsigned int	pipe_build(int *pipe_in, int *pipe_out);
void			free_cmd_path(t_exec_ctx *exec);
void			fd_close_reset(int *pipein, int *pipeout, int *prevfd);
void    		init_exec_ctx(t_exec_ctx *exec);
unsigned int	track_node(t_cmd_node *node, t_ctx *ctx);
unsigned int	cmd_exec(t_ctx *ctx, t_exec_ctx *exec, t_array *argv);
unsigned int	cmd_exec_bin(char *argv[], t_env *env, t_exec_ctx *exec);
pid_t			cmd_exec_fork(char *argv[], t_exec_ctx *exec, t_env *env);
unsigned int	cmd_exec_get_path(char *cmd_name, t_exec_ctx *exec, t_env *env);
unsigned int    handle_and_sign(t_cmd_node *node, t_ctx *ctx);
unsigned int	handle_or_sign(t_cmd_node *node, t_ctx *ctx);
unsigned int	handle_single_command(t_cmd_node *node, t_ctx *ctx, t_exec_ctx *exec_ctx);
unsigned int    handle_pipe_sign(t_cmd_node *node, t_exec_ctx *exec_ctx, t_ctx *ctx);
pid_t			exec_pipeline(t_list *list, t_exec_ctx *exec_ctx, t_ctx *ctx);

#endif
