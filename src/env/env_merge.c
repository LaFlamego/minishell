/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_merge.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 04:28:25 by Oery              #+#    #+#             */
/*   Updated: 2026/03/23 04:28:35 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/env.h"

// Merge two environments. If a key is in both, the one in DST will be kept.
// FIXME: ft_env_set will return an error
void	env_merge(t_env *dst, t_env *src)
{
	size_t	i;
	char	*key;

	i = 0;
	while (i < src->size - 1)
	{
		key = src->data[i];
		if (!env_find(dst, key))
		{
			if (ft_strchr(key, '='))
				env_set(dst, key);
		}
		i++;
	}
}
