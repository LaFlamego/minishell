/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:14:54 by Oery              #+#    #+#             */
/*   Updated: 2026/01/06 16:58:11 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

void	set_precision(const char **fmt, t_flags *flags)
{
	(*fmt)++;
	flags->precision = ft_read_int(fmt);
}

int	handle_directive(const char **fmt, va_list *ap, int fd)
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

int	ft_printf(const char *fmt, ...)
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
			i += handle_directive(&fmt, &ap, 1);
		else
			i += ft_printf_put(&fmt, 1);
	}
	va_end(ap);
	return (i);
}
