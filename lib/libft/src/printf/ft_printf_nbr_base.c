/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 21:00:22 by Oery              #+#    #+#             */
/*   Updated: 2026/03/13 18:15:53 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft/printf.h"

// #include <unistd.h>

static int	validate_base(char *base)
{
	char	*start;
	int		len;

	len = 0;
	while (*base)
	{
		++len;
		start = base;
		if (*base == '+' || *base == '-')
			return (0);
		while (*start)
		{
			if (*start == *base && start != base)
				return (0);
			++start;
		}
		++base;
	}
	if (len < 2)
		return (0);
	return (len);
}

static int	ft_printf_nbr_base_rec(long nbr, int base, char *base_str, int fd)
{
	int	i;
	int	rem;

	i = 0;
	rem = nbr % base;
	nbr /= base;
	if (nbr < 0 || rem < 0)
	{
		i += ft_putchar_fd('-', fd);
		rem *= -1;
		nbr *= -1;
	}
	if (nbr > 0)
		i += ft_printf_nbr_base_rec(nbr, base, base_str, fd);
	i += ft_putchar_fd(base_str[rem], fd);
	return (i);
}

static int	ft_length_nbr_base_rec(long nbr, int base)
{
	int	i;
	int	rem;

	i = 0;
	rem = nbr % base;
	nbr /= base;
	if (nbr < 0 || rem < 0)
	{
		i++;
		rem *= -1;
		nbr *= -1;
	}
	if (nbr > 0)
		i += ft_length_nbr_base_rec(nbr, base);
	i++;
	return (i);
}

int	ft_length_nbr_base(long nbr, char *base, t_flags *flags)
{
	int	i;
	int	base_int;

	base_int = validate_base(base);
	if (base_int == 0)
		return (0);
	i = 0;
	if (nbr >= 0)
	{
		if (flags->style & STYLE_EXPLICIT_SIGN)
			i += 1;
		else if (flags->style & STYLE_SPACE_SIGN)
			i += 1;
	}
	i += ft_length_nbr_base_rec(nbr, base_int);
	return (i);
}

int	ft_printf_nbr_base(long nbr, char *base, t_flags *flags, int fd)
{
	int	i;
	int	base_int;

	base_int = validate_base(base);
	if (base_int == 0)
		return (0);
	i = 0;
	if (nbr >= 0)
	{
		if ((flags->style & STYLE_EXPLICIT_SIGN))
			i += ft_putchar_fd('+', fd);
		else if ((flags->style & STYLE_SPACE_SIGN))
			i += ft_putchar_fd(' ', fd);
	}
	i += ft_printf_nbr_base_rec(nbr, base_int, base, fd);
	return (i);
}
