/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:38:57 by Oery              #+#    #+#             */
/*   Updated: 2025/11/12 23:17:32 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, char c)
{
	char	*last;

	last = 0;
	while (*s)
	{
		if ((unsigned char) *s == (unsigned char) c)
			last = (char *) s;
		s++;
	}
	if ((unsigned char) *s == (unsigned char) c)
		last = (char *) s;
	return (last);
}
