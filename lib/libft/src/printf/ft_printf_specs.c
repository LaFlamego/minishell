/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_specs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 17:47:28 by Oery              #+#    #+#             */
/*   Updated: 2026/01/06 17:32:14 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_spec(char c)
{
	char	*specs;

	specs = "%cspdiuxX";
	while (*specs)
	{
		if (*specs == c)
			return (1);
		specs++;
	}
	return (0);
}

int	handle_spec(const char **fmt, t_flags *flags, va_list *ap, int fd)
{
	int	i;

	i = 0;
	if (**fmt == '%')
		i += ft_putchar_fd('%', fd);
	else if (**fmt == 'c')
		i += ft_printf_char(ap, flags, fd);
	else if (**fmt == 'd' || **fmt == 'i')
		i += ft_printf_nbr(ap, flags, fd);
	else if (**fmt == 'u')
		i += ft_printf_nbr_u(ap, flags, fd);
	else if (**fmt == 's')
		i += ft_printf_str(ap, flags, fd);
	else if (**fmt == 'x')
		i += ft_printf_hex_l(ap, flags, fd);
	else if (**fmt == 'X')
		i += ft_printf_hex_u(ap, flags, fd);
	else if (**fmt == 'p')
		i += ft_printf_ptr(ap, flags, fd);
	(*fmt)++;
	return (i);
}
