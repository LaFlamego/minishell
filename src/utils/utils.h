/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 21:22:12 by Oery              #+#    #+#             */
/*   Updated: 2026/04/28 22:08:18 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "src/env/env.h"
// Required for readline/history
# include <stdio.h>

/**
 * history_load() - load the command history
 * @env: environment variables
 *
 * Opens $HISTFILE and adds every line to the history.
 *
 * On failure, does nothing.
 */
void	history_load(t_env *env);

/**
 * history_save() - save a line to the history
 * @env: environment variables
 * @line: the command to save
 *
 * Opens $HISTFILE in append mode, creating the file if not existing.
 * Then writes the line to the file, followed by a new line.
 *
 * On failure, does nothing.
 */
void	history_save(t_env *env, const char *line);

#endif
