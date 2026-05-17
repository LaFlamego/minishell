/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 20:21:43 by Oery              #+#    #+#             */
/*   Updated: 2026/05/18 00:40:41 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include "src/cmd/exec/exec.h"
# include "src/cmd/tree/word/word.h"
# include "src/env/env.h"

// TODO: This should be renamed to preprocess or whatever

/**
 * expand_command() - expand a command
 * @words: a command's content
 * @ctx: command execution context
 *
 * Setup redirections and build the command's `argv`
 *
 * Return:
 * Pointer to `argv` on success. Must be freed.
 * NULL on failure.
 */
t_array	*expand_command(t_word *words, t_exec_ctx *ctx);

// TODO: add documentation
int		expand_variable(t_string *arg, char *key, t_env *env);

char	*expand_target(t_word *parts, t_env *env);

int		expand_word(t_list *parts, t_array *argv, t_exec_ctx *ctx);

int		expand_redirection(t_word_part *part, t_exec_ctx *ctx);

char	*expand_filter(t_list *parts);
int		expand_files(t_array *argv, t_env *env, char *filter);

int		expand_heredoc(t_word_part *part, t_string *arg);

int		preprocess_heredocs(t_cmd_node *node, t_env *env);

int		redirect_in(char *file_to, t_exec_ctx *exec_ctx);
int		redirect_out(char *file_to, t_exec_ctx *exec_ctx);
int		redirect_in_until(char *del, t_env *env);
int		redirect_out_append(char *file_to, t_exec_ctx *exec_ctx);

#endif
