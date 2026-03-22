/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr_u_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 21:00:22 by Oery              #+#    #+#             */
/*   Updated: 2026/03/22 19:40:19 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../put/ft_put.h"
#include "ft_printf.h"

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

static int	ft_printrec(unsigned long nbr, int base, char *base_str, int fd)
{
	int	i;
	int	rem;

	i = 0;
	rem = nbr % base;
	nbr /= base;
	if (nbr > 0)
		i += ft_printrec(nbr, base, base_str, fd);
	i += ft_putchar_fd(base_str[rem], fd);
	return (i);
}

static int	ft_length_nbr_u_base_rec(unsigned long nbr, int base)
{
	int	i;

	i = 0;
	nbr /= base;
	if (nbr > 0)
		i += ft_length_nbr_u_base_rec(nbr, base);
	i++;
	return (i);
}

int	ft_length_nbr_u_base(unsigned long nbr, char *base)
{
	int	base_int;

	base_int = validate_base(base);
	if (base_int == 0)
		return (0);
	return (ft_length_nbr_u_base_rec(nbr, base_int));
}

int	ft_printf_nbr_u_base(unsigned long nbr, char *base, int fd)
{
	int	base_int;

	base_int = validate_base(base);
	if (base_int == 0)
		return (0);
	return (ft_printrec(nbr, base_int, base, fd));
}
