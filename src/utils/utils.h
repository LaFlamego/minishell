/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 21:22:12 by Oery              #+#    #+#             */
/*   Updated: 2026/04/28 23:14:29 by Oery             ###   ########.fr       */
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

/**
 * setup_signal_handlers() - register the signal handlers
 *
 * Return:
 * On success, 1.
 * On failure, 0.
 */
int		setup_signals_handlers(void);

/**
 * dir_get_files - list entries in a directory
 * @path: path to directory (must not be NULL)
 *
 * Returns an array of allocated strings containing
 * directory entry names, excluding hidden files.
 *
 * Return: pointer to array on success, NULL on failure.
 * Caller must free each string and the array.
 */
t_array	*dir_get_files(const char *path);

#endif
