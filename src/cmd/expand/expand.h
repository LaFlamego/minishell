/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 20:21:43 by Oery              #+#    #+#             */
/*   Updated: 2026/04/26 21:46:16 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include "src/cmd/tree/word/word.h"
# include "src/env/env.h"

// TODO: This should be renamed to preprocess or whatever

/**
 * expand_command() - expand a command
 * @words: a command's content
 * @env: environment variables
 *
 * Setup redirections and build the command's `argv`
 *
 * Return:
 * Pointer to `argv` on success. Must be freed.
 * NULL on failure.
 */
t_array	*expand_command(t_word *words, t_env *env);

#endif
