/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:40:01 by Oery              #+#    #+#             */
/*   Updated: 2025/11/13 20:23:01 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		length;

	length = ft_strlen(s1) + ft_strlen(s2);
	result = malloc((length + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[0] = '\0';
	ft_strlcat(result, s1, length + 1);
	ft_strlcat(result, s2, length + 1);
	return (result);
}
