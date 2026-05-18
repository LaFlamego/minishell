/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 21:22:12 by Oery              #+#    #+#             */
/*   Updated: 2026/05/18 23:23:05 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "src/ctx/ctx.h"
# include "src/env/env.h"
# include <signal.h>
# include <stdio.h>

extern volatile sig_atomic_t	g_signal;

/**
 * enum e_cli_error - cli errors
 */
enum							e_cli_error
{
	CLI_MISSING_ARGUMENT,
	CLI_INVALID_OPTION,
	CLI_NOT_AN_OPTION,
};

/**
 * setup_signal_handlers() - register the signal handlers
 *
 * Return:
 * On success, 1.
 * On failure, 0.
 */
int								setup_signals_handlers(void);

/**
 * dir_get_files() - list entries in a directory
 * @path: path to directory (must not be NULL)
 * @filter: the filter to apply on file names
 *
 * Returns an array of allocated strings containing
 * directory entry names, excluding hidden files.
 *
 * Return: pointer to array on success, NULL on failure.
 * Caller must free each string and the array.
 */
t_array							*dir_get_files(const char *path, char *filter);

void							files_sort(t_array *files);
bool							is_filtered(char *file, char *filter);

/**
 * cli_parse_args() - parse cli arguments
 * @argc: length of argv
 * @argv: argument list
 * @ctx: shell context
 *
 * Parse the arguments of the CLI and set the corresponding flags.
 *
 * Return:
 * On success, 1
 * On failure, 0
 */
int								cli_parse_args(int argc, char **argv,
									t_ctx *ctx);

#endif
