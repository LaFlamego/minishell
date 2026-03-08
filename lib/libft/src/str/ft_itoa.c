/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:28:11 by Oery              #+#    #+#             */
/*   Updated: 2025/11/13 15:28:35 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_int_length(int n)
{
	int		length;
	long	ln;

	ln = (long) n;
	length = 1;
	if (ln < 0)
	{
		length++;
		ln = -ln;
	}
	while (ln / 10 >= 1)
	{
		ln = ln / 10;
		length++;
	}
	return (length);
}

static void	ft_write_next_digit(int n, char *s)
{
	int	quotient;
	int	remainder;

	quotient = n / 10;
	remainder = n % 10;
	if (quotient != 0)
		ft_write_next_digit(quotient, s - 1);
	if (remainder < 0)
		remainder = -remainder;
	*s = remainder + '0';
}

char	*ft_itoa(int n)
{
	char	*result;
	int		length;

	length = ft_int_length(n);
	result = malloc((length + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	if (n < 0)
		result[0] = '-';
	ft_write_next_digit(n, result + length - 1);
	result[length] = '\0';
	return (result);
}
