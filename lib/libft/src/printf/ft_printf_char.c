/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 20:40:04 by Oery              #+#    #+#             */
/*   Updated: 2026/03/13 18:14:20 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/printf.h"
#include <stdarg.h>
#include <unistd.h>

int	ft_printf_char(va_list *ap, t_flags *flags, int fd)
{
	char	c;
	int		i;

	i = 1;
	c = (unsigned char)va_arg(*ap, int);
	if (!(flags->style & STYLE_JUSTIFY_LEFT))
		i += ft_pad(flags, i, fd);
	write(fd, &c, 1);
	if (flags->style & STYLE_JUSTIFY_LEFT)
		i += ft_pad(flags, i, fd);
	return (i);
}
