/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 16:07:45 by Oery              #+#    #+#             */
/*   Updated: 2026/03/22 19:37:42 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../put/ft_put.h"
#include "ft_printf.h"
#include <unistd.h>

int	ft_pad(t_flags *flags, int length, int fd)
{
	char	c;
	int		i;

	c = ' ';
	if (flags->style & STYLE_PAD_ZERO && flags->precision == -1)
		c = '0';
	i = 0;
	while (i < flags->min_width - length)
	{
		write(fd, &c, 1);
		i++;
	}
	return (i);
}

int	ft_pad_precision(t_flags *flags, int len, int fd)
{
	int	i;

	i = 0;
	while (i < flags->precision - len)
		i += ft_putchar_fd('0', fd);
	return (i);
}
