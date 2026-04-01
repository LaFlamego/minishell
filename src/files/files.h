/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:37:35 by Oery              #+#    #+#             */
/*   Updated: 2026/03/27 13:29:45 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILES_H
# define FILES_H

# include "libft.h"

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
