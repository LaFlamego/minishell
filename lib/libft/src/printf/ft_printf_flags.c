/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 19:55:58 by Oery              #+#    #+#             */
/*   Updated: 2026/03/13 18:14:38 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/printf.h"
#include <stdarg.h>
#include <stdlib.h>

t_flags	*new_flags(void)
{
	t_flags	*flags;

	flags = malloc(sizeof(t_flags));
	if (!flags)
		return (NULL);
	flags->min_width = 0;
	flags->precision = -1;
	flags->style = 0;
	return (flags);
}

void	set_flag(const char **fmt, t_flags *flags)
{
	if (**fmt == '-')
		flags->style |= STYLE_JUSTIFY_LEFT;
	else if (**fmt == '#')
		flags->style |= STYLE_ALTERNATE;
	else if (**fmt == '0')
		flags->style |= STYLE_PAD_ZERO;
	else if (**fmt == '+')
		flags->style |= STYLE_EXPLICIT_SIGN;
	else if (**fmt == ' ')
		flags->style |= STYLE_SPACE_SIGN;
	(*fmt)++;
}

int	is_flag(char c)
{
	char	*flags;

	flags = "-0# +";
	while (*flags)
	{
		if (*flags == c)
			return (1);
		flags++;
	}
	return (0);
}
