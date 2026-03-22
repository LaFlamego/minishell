/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endswith.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 12:42:18 by Oery              #+#    #+#             */
/*   Updated: 2026/03/22 19:22:29 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

int	ft_endswith(const char *string, const char *suffix)
{
	int	len_suffix;
	int	len_string;

	len_suffix = ft_strlen(suffix);
	len_string = ft_strlen(string);
	string += len_string - len_suffix;
	return (ft_streq(string, suffix));
}
