/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 14:35:08 by Oery              #+#    #+#             */
/*   Updated: 2026/05/14 15:21:00 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../str/ft_str.h"
#include "../string/ft_string.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

static size_t	push_string(va_list *ap, t_string *string)
{
	char	*arg;

	arg = va_arg(*ap, char *);
	if (arg)
		return (ft_string_push_str(string, arg));
	else
		return (ft_string_push_str(string, "(nil)"));
}

static t_string	*handle_char(const char **fmt, t_string *result, va_list *ap)
{
	if (ft_startswith(*fmt, "%s"))
	{
		*fmt += 1;
		if (!push_string(ap, result))
			return (NULL);
	}
	else
	{
		if (!ft_string_push(result, **fmt))
			return (NULL);
	}
	*fmt += 1;
	return (result);
}

// TODO: Test a bit
char	*ft_format(const char *fmt, ...)
{
	t_string	*result;
	char		*inner;
	va_list		ap;

	if (fmt == NULL)
		return (NULL);
	result = ft_string_new(0);
	if (!result)
		return (NULL);
	va_start(ap, fmt);
	while (*fmt)
	{
		if (!handle_char(&fmt, result, &ap))
		{
			ft_string_free(result);
			return (NULL);
		}
	}
	va_end(ap);
	inner = result->content;
	free(result);
	return (inner);
}
