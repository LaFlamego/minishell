/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startswith.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 18:32:05 by Oery              #+#    #+#             */
/*   Updated: 2026/03/11 18:33:30 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_startswith(const char *string, const char *prefix)
{
	size_t	len_prefix;

	len_prefix = ft_strlen(prefix);
	return (ft_strncmp(string, prefix, len_prefix));
}
