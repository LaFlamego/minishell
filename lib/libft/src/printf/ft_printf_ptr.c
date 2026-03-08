/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 21:03:21 by Oery              #+#    #+#             */
/*   Updated: 2026/01/06 17:28:54 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

static int	handle_null(t_flags *flags, int fd)
{
	int	i;

	i = 0;
	if (!(flags->style & STYLE_JUSTIFY_LEFT))
		i += ft_pad(flags, ft_strlen("(nil)"), fd);
	i += ft_putstr_fd("(nil)", fd);
	if (flags->style & STYLE_JUSTIFY_LEFT)
		i += ft_pad(flags, i, fd);
	return (i);
}

static	int	max_size(t_flags *flags, int len)
{
	if (flags->precision > len)
		return (ft_strlen("0x") + flags->precision);
	else
		return (ft_strlen("0x") + len);
}

int	ft_printf_ptr(va_list *ap, t_flags *flags, int fd)
{
	int				i;
	int				len;
	unsigned long	ptr;

	i = 0;
	ptr = (unsigned long) va_arg(*ap, void *);
	if (ptr == 0)
		return (handle_null(flags, fd));
	len = ft_length_nbr_u_base(ptr, "0123456789abcdef");
	if (!(flags->style & STYLE_JUSTIFY_LEFT))
		i += ft_pad(flags, max_size(flags, len), fd);
	i += ft_putstr_fd("0x", fd);
	i += ft_pad_precision(flags, len, fd);
	i += ft_printf_nbr_u_base(ptr, "0123456789abcdef", fd);
	if (flags->style & STYLE_JUSTIFY_LEFT)
		i += ft_pad(flags, i, fd);
	return (i);
}
