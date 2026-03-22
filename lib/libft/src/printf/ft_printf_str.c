/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 20:38:24 by Oery              #+#    #+#             */
/*   Updated: 2026/03/22 19:42:34 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../put/ft_put.h"
#include "../str/ft_str.h"
#include "ft_printf.h"
#include <stdarg.h>

#define MAX_PRECISION 6

static int	max_size(t_flags *flags, char *str)
{
	if (str == NULL)
	{
		if (flags->precision == -1 || flags->precision >= MAX_PRECISION)
			return (MAX_PRECISION);
		return (0);
	}
	if (flags->precision != -1
		&& (unsigned long)flags->precision < ft_strlen(str))
		return (flags->precision);
	return (ft_strlen(str));
}

static int	handle_null(t_flags *flags, int fd)
{
	int	i;

	i = 0;
	if (!(flags->style & STYLE_JUSTIFY_LEFT))
		i += ft_pad(flags, max_size(flags, NULL), fd);
	if (flags->precision == -1 || flags->precision >= 6)
		i += ft_putstr_fd("(null)", fd);
	if (flags->style & STYLE_JUSTIFY_LEFT)
		i += ft_pad(flags, i, fd);
	return (i);
}

int	ft_printf_str(va_list *ap, t_flags *flags, int fd)
{
	char	*str;
	int		i;

	str = va_arg(*ap, char *);
	if (str == NULL)
		return (handle_null(flags, fd));
	i = 0;
	if (!(flags->style & STYLE_JUSTIFY_LEFT))
		i += ft_pad(flags, max_size(flags, str), fd);
	i += ft_putstr_fd_max(str, fd, flags->precision);
	if (flags->style & STYLE_JUSTIFY_LEFT)
		i += ft_pad(flags, i, fd);
	return (i);
}
