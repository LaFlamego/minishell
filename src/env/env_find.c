/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 04:28:46 by Oery              #+#    #+#             */
/*   Updated: 2026/03/23 04:29:15 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/env.h"

static bool	is_key(const char *var, const char *key)
{
	int	i;

	if (!var || !key)
		return (false);
	i = 0;
	while (var[i] && key[i] && var[i] == key[i])
	{
		if (var[i] == '=' || key[i] == '=')
			break ;
		i++;
	}
	if (var[i] == '=' && key[i] == '\0')
		return (true);
	if (key[i] == '=' && var[i] == '\0')
		return (true);
	if (key[i] == '=' && var[i] == '=')
		return (true);
	if (key[i] == '\0' && var[i] == '\0')
		return (true);
	return (false);
}

char	**env_find(t_env *env, char *key)
{
	size_t	i;

	i = 0;
	while (i < env->size)
	{
		if (is_key(env->data[i], key))
			return ((char **)env->data + i);
		i++;
	}
	return (NULL);
}
