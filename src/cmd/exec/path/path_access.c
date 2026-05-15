/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_access.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 15:47:14 by Oery              #+#    #+#             */
/*   Updated: 2026/05/15 15:51:54 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

bool	file_exists(const char *path)
{
	return (access(path, F_OK) == 0);
}

bool	has_exe_perm(const char *path)
{
	return (access(path, X_OK) == 0);
}
