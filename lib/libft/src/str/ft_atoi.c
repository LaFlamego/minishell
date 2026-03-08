/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:29:55 by Oery              #+#    #+#             */
/*   Updated: 2025/11/13 20:20:43 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c >= '\t' && c <= '\r')
		return (1);
	return (c == ' ');
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		sign = 1;
		str++;
	}
	result = 0;
	while (ft_isdigit(*str))
	{
		result *= 10;
		result += sign * (*str - 48);
		str++;
	}
	return (result);
}
