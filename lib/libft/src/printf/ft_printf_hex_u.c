/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 22:18:30 by Oery              #+#    #+#             */
/*   Updated: 2026/03/13 18:15:24 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft/printf.h"
#include <stdarg.h>

static int	max_size(t_flags *flags, unsigned int n, int len)
{
	int	prefix;

	prefix = 0;
	if (n > 0 && flags->style & STYLE_ALTERNATE)
		prefix = ft_strlen("0x");
	if (flags->precision == 0 && n == 0)
		return (0);
	else if (flags->precision > len)
		return (prefix + flags->precision);
	else
		return (prefix + len);
}

int	ft_printf_hex_u(va_list *ap, t_flags *flags, int fd)
{
	unsigned int	n;
	int				i;
	int				len;

	n = (unsigned int)va_arg(*ap, long);
	len = ft_length_nbr_base(n, "0123456789ABCDEF", flags);
	i = 0;
	if (!(flags->style & STYLE_JUSTIFY_LEFT))
		i += ft_pad(flags, max_size(flags, n, len), fd);
	if (n > 0 && flags->style & STYLE_ALTERNATE)
		i += ft_putstr_fd("0X", fd);
	i += ft_pad_precision(flags, len, fd);
	if (flags->precision != 0 || n != 0)
		i += ft_printf_nbr_base(n, "0123456789ABCDEF", flags, fd);
	if (flags->style & STYLE_JUSTIFY_LEFT)
		i += ft_pad(flags, i, fd);
	return (i);
}
