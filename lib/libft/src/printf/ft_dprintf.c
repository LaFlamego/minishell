/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 17:49:35 by Oery              #+#    #+#             */
/*   Updated: 2026/03/13 18:13:32 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

static void	set_precision(const char **fmt, t_flags *flags)
{
	(*fmt)++;
	flags->precision = ft_read_int(fmt);
}

static int	handle_directive(const char **fmt, va_list *ap, int fd)
{
	int		i;
	t_flags	*flags;

	i = 0;
	(*fmt)++;
	flags = new_flags();
	if (!flags)
		return (-1);
	while (is_flag(**fmt))
		set_flag(fmt, flags);
	flags->min_width = ft_read_int(fmt);
	if (**fmt == '.')
		set_precision(fmt, flags);
	if (is_spec(**fmt))
		i += handle_spec(fmt, flags, ap, fd);
	free(flags);
	return (i);
}

int	ft_dprintf(int fd, const char *fmt, ...)
{
	int		i;
	va_list	ap;

	if (fmt == NULL)
		return (-1);
	i = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
			i += handle_directive(&fmt, &ap, fd);
		else
			i += ft_printf_put(&fmt, fd);
	}
	va_end(ap);
	return (i);
}
