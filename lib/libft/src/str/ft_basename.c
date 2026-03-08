/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:04:50 by Oery              #+#    #+#             */
/*   Updated: 2026/02/02 11:13:40 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_basename(const char *path)
{
	char	*result;

	if (!path)
		return (NULL);
	if (path[0] == '.')
		return ((char *)path);
	result = ft_strrchr(path, '/');
	if (!result)
		return ((char *)path);
	return (result + 1);
}
