/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 20:44:57 by Oery              #+#    #+#             */
/*   Updated: 2026/01/06 17:43:35 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <unistd.h>

static int	ft_length_nbr_rec(int n)
{
	int	i;
	int	quo;
	int	rem;

	i = 0;
	quo = n / 10;
	rem = n % 10;
	if (quo != 0)
		i += ft_length_nbr_rec(quo);
	if (rem < 0)
		rem = -rem;
	i++;
	return (i);
}

static	int	max_size(t_flags *flags, int n, int len)
{
	int	prefix;

	if (flags->precision == 0 && n == 0)
		return (0);
	prefix = 0;
	if (n < 0)
		prefix = 1;
	else if (flags->style & STYLE_EXPLICIT_SIGN)
		prefix = 1;
	else if (flags->style & STYLE_SPACE_SIGN)
		prefix = 1;
	if (flags->precision > len)
		return (prefix + flags->precision);
	else
		return (prefix + len);
}

static int	ft_printf_nbr_rec(int n, int fd)
{
	int	i;
	int	quo;
	int	rem;

	i = 0;
	quo = n / 10;
	rem = n % 10;
	if (quo != 0)
		i += ft_printf_nbr_rec(quo, fd);
	if (rem < 0)
		rem = -rem;
	i += ft_putchar_fd(rem + '0', fd);
	return (i);
}

static	int	ft_printf_sign(t_flags *flags, int n, int fd)
{
	if (n < 0)
		return (ft_putchar_fd('-', fd));
	else if (flags->style & STYLE_EXPLICIT_SIGN)
		return (ft_putchar_fd('+', fd));
	else if (flags->style & STYLE_SPACE_SIGN)
		return (ft_putchar_fd(' ', fd));
	return (0);
}

int	ft_printf_nbr(va_list *ap, t_flags *flags, int fd)
{
	int	len;
	int	i;
	int	n;

	i = 0;
	n = va_arg(*ap, int);
	len = ft_length_nbr_rec(n);
	if (!(flags->style & STYLE_JUSTIFY_LEFT)
		&& (!(flags->style & STYLE_PAD_ZERO) || flags->precision != -1))
		i += ft_pad(flags, max_size(flags, n, len), fd);
	i += ft_printf_sign(flags, n, fd);
	if (flags->style & STYLE_PAD_ZERO && flags->precision == -1)
		i += ft_pad(flags, max_size(flags, n, len), fd);
	i += ft_pad_precision(flags, len, fd);
	if (flags->precision != 0 || n != 0)
		i += ft_printf_nbr_rec(n, fd);
	if (flags->style & STYLE_JUSTIFY_LEFT)
		i += ft_pad(flags, i, fd);
	return (i);
}
