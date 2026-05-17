/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_take.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 03:01:23 by Oery              #+#    #+#             */
/*   Updated: 2026/05/17 03:02:07 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_string.h"
#include <stdlib.h>

char	*ft_string_take(t_string *s)
{
	char	*tmp;

	tmp = s->content;
	free(s);
	return (tmp);
}
