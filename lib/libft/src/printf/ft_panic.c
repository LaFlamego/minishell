/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_panic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 22:47:21 by Oery              #+#    #+#             */
/*   Updated: 2026/03/13 18:13:55 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/printf.h"
#include <stdarg.h>
#include <stdlib.h>

static void	set_precision(const char **fmt, t_flags *flags)
{
	(*fmt)++;
	flags->precision = ft_read_int(fmt);
}

static int	handle_directive(const char **fmt, va_list *ap)
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
		i += handle_spec(fmt, flags, ap, 2);
	free(flags);
	return (i);
}

void	ft_panic(int status, const char *fmt, ...)
{
	va_list	ap;

	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
			handle_directive(&fmt, &ap);
		else
			ft_printf_put(&fmt, 2);
	}
	va_end(ap);
	exit(status);
}
