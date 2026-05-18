/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_from.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 04:30:09 by Oery              #+#    #+#             */
/*   Updated: 2026/05/18 22:55:14 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./env.h"
#include <stdlib.h>

t_env	*env_from(char **envp)
{
	t_env	*env;
	size_t	i;
	char	*new;

	env = ft_array_new();
	if (!env)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		new = ft_strdup(envp[i]);
		if (!new)
			return (env_free(env));
		if (!ft_array_push(env, new) || !env->data[i])
		{
			free(new);
			return (env_free(env));
		}
		i++;
	}
	if (!ft_array_push(env, NULL))
		return (env_free(env));
	return (env);
}
