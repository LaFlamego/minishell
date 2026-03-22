/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:38:08 by Oery              #+#    #+#             */
/*   Updated: 2026/03/22 19:18:51 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_put.h"

#define BASE 10

static void	ft_putnbr_rec(int n, int fd)
{
	int	quotient;
	int	remainder;

	quotient = n / BASE;
	remainder = n % BASE;
	if (quotient != 0)
		ft_putnbr_rec(quotient, fd);
	if (remainder < 0)
		remainder = -remainder;
	ft_putchar_fd(remainder + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	ft_putnbr_rec(n, fd);
}
