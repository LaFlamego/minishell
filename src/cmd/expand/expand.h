/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 20:21:43 by Oery              #+#    #+#             */
/*   Updated: 2026/05/07 20:41:52 by Oery             ###   ########.fr       */
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
 * @env: environment variables
 * @ctx: command execution context
 *
 * Setup redirections and build the command's `argv`
 *
 * Return:
 * Pointer to `argv` on success. Must be freed.
 * NULL on failure.
 */
t_array	*expand_command(t_word *words, t_env *env, t_exec_ctx *ctx);

// TODO: add documentation
int		expand_variable(t_string *arg, char *key, t_env *env);

char	*expand_target(t_word *parts, t_env *env, bool is_heredoc);

void	redirect_in(char *file_to, t_exec_ctx *exec_ctx);
void	redirect_out(char *file_to, t_exec_ctx *exec_ctx);
void	redirect_in_until(t_exec_ctx *exec_ctx, char *limiter);
void	redirect_out_append(char *file_to, t_exec_ctx *exec_ctx);

#endif
