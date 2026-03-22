/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:29:03 by Oery              #+#    #+#             */
/*   Updated: 2026/03/22 19:22:47 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	int				length;
	char			*result;

	if (s == NULL || f == NULL)
		return (NULL);
	length = ft_strlen(s);
	result = malloc((length + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[length] = '\0';
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	return (result);
}
