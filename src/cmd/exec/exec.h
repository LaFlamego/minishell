/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 21:05:59 by Oery              #+#    #+#             */
/*   Updated: 2026/05/15 19:49:12 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "../tree/node.h"
# include "src/ctx/ctx.h"
# include "src/cmd/tree/word/word.h"
# include <sys/types.h>

enum					e_redir
{
	READ_IN,
	WRITE_OUT,
	HEREDOC,
	APPEND,
	NO_REDIR,
};

typedef struct s_cmd
{
	char				*path;
}						t_cmd;

typedef struct s_exec_fds
{
	int					in;
	int					out;
	int					stdin_tpr;
	int					stdout_tpr;
	int					heredoc;
}						t_exec_fd;

typedef struct s_exec_pipe
{
	size_t				index;
	int					fd;
}						t_exec_pipe;

typedef struct s_exec_ctx
{
	size_t				args_nb;
	bool				is_pipe;
	enum e_redir		redir;
	struct s_cmd		cmd;
	struct s_exec_fds	fd;
	struct s_exec_pipe	pipe;
	t_env				*env;
	t_ctx				*shell;
}						t_exec_ctx;

unsigned int			pipe_build(int *pipe_in, int *pipe_out);
void					free_cmd_path(t_exec_ctx *exec);
void					fd_close_reset(int *pipein, int *pipeout, int *prevfd);
void					init_exec_ctx(t_exec_ctx *exec, t_ctx *ctx);
void					redir_fd(t_exec_ctx *exec, bool to_save_stdio);
void					restore_stdio(t_exec_ctx *exec);
void					close_heredocs_in_words(t_word *words);
void					close_other_heredocs(t_list *head, t_cmd_node *current);
unsigned int			track_node(t_cmd_node *node, t_ctx *ctx);
unsigned int			cmd_exec(t_ctx *ctx, t_exec_ctx *exec, t_array *argv);
unsigned int			cmd_exec_bin(t_array *argv, t_env *env,
							t_exec_ctx *exec);
pid_t					cmd_exec_fork(t_array *argv, t_exec_ctx *exec,
							t_env *env);
unsigned int			handle_and_sign(t_cmd_node *node, t_ctx *ctx);
unsigned int			handle_or_sign(t_cmd_node *node, t_ctx *ctx);
unsigned int			handle_single_command(t_cmd_node *node, t_ctx *ctx,
							t_exec_ctx *exec_ctx);
unsigned int			handle_pipe_sign(t_cmd_node *node, t_exec_ctx *exec_ctx,
							t_ctx *ctx);
pid_t					exec_pipeline(t_list *curr, t_list *head,
							t_exec_ctx *exec_ctx, t_ctx *ctx);

#endif
