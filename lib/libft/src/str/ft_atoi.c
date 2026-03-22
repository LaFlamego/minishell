/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:29:55 by Oery              #+#    #+#             */
/*   Updated: 2026/03/22 19:20:14 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../char/ft_char.h"

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
