/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 15:17:10 by Oery              #+#    #+#             */
/*   Updated: 2026/05/19 00:56:46 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./path.h"
#include "libft.h"
#include <errno.h>
#include <string.h>

static char	*get_error_message(enum e_access_result res)
{
	if (res == FILE_NOT_FOUND)
		return ("No such file or directory");
	if (res == CMD_NOT_FOUND)
		return ("command not found");
	if (res == ACCESS_DENIED)
		return ("Permission denied");
	if (res == IS_DIR)
		return ("Is a directory");
	if (res == ERRNO)
		return (strerror(errno));
	return (NULL);
}

static unsigned int	get_return_code(enum e_access_result res)
{
	if (res == FILE_NOT_FOUND)
		return (127);
	if (res == CMD_NOT_FOUND)
		return (127);
	if (res == ACCESS_DENIED)
		return (126);
	if (res == IS_DIR)
		return (126);
	return (1);
}

unsigned int	path_error(enum e_access_result res, char *cmd)
{
	char			*msg;
	unsigned int	ret;

	if (res == OK)
		return (1);
	msg = get_error_message(res);
	ret = get_return_code(res);
	ft_dprintf(2, "minishell: %s: %s\n", cmd, msg);
	return (ret);
}
