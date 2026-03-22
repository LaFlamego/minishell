/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_max.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:22:26 by Oery              #+#    #+#             */
/*   Updated: 2026/03/22 19:19:52 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_put.h"

int	ft_putstr_fd_max(char *s, int fd, int max)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (max != -1 && i >= max)
			return (i);
		i += ft_putchar_fd(s[i], fd);
	}
	return (i);
}
