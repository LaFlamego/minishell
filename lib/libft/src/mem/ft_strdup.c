/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:01:48 by Oery              #+#    #+#             */
/*   Updated: 2026/03/22 19:16:21 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../str/ft_str.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		length;
	char	*result;

	length = ft_strlen(s);
	result = malloc((length + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[length] = '\0';
	while (length >= 0)
	{
		result[length] = s[length];
		length--;
	}
	return (result);
}
