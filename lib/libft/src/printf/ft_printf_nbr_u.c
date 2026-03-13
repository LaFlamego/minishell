/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:41:24 by Oery              #+#    #+#             */
/*   Updated: 2026/03/13 18:19:33 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft/printf.h"
#include <stdarg.h>

static int	ft_length_nbr_u_rec(unsigned int n)
{
	int	i;
	int	quo;

	i = 0;
	quo = n / 10;
	if (quo != 0)
		i += ft_length_nbr_u_rec(quo);
	i++;
	return (i);
}

static int	max_size(t_flags *flags, unsigned int n, int len)
{
	if (flags->precision == 0 && n == 0)
		return (0);
	else if (flags->precision > len)
		return (flags->precision);
	else
		return (len);
}

static int	ft_printf_nbr_u_rec(unsigned int n, int fd)
{
	int	i;
	int	quo;
	int	rem;

	i = 0;
	quo = n / 10;
	rem = n % 10;
	if (quo != 0)
		i += ft_printf_nbr_u_rec(quo, fd);
	i += ft_putchar_fd(rem + '0', fd);
	return (i);
}

int	ft_printf_nbr_u(va_list *ap, t_flags *flags, int fd)
{
	int				len;
	int				i;
	unsigned int	n;

	i = 0;
	n = va_arg(*ap, unsigned int);
	len = ft_length_nbr_u_rec(n);
	if (!(flags->style & STYLE_JUSTIFY_LEFT))
		i += ft_pad(flags, max_size(flags, n, len), fd);
	i += ft_pad_precision(flags, len, fd);
	if (flags->precision != 0 || n != 0)
		i += ft_printf_nbr_u_rec(n, fd);
	if (flags->style & STYLE_JUSTIFY_LEFT)
		i += ft_pad(flags, i, fd);
	return (i);
}
