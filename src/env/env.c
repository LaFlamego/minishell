/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 19:01:43 by Oery              #+#    #+#             */
/*   Updated: 2026/04/28 19:46:46 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./env.h"
#include "libft.h"
#include <stdlib.h>

char	*env_get(t_env *env, char *key)
{
	char	**var;

	var = env_find(env, key);
	if (!var)
		return (NULL);
	return (ft_strchr(*var, '=') + 1);
}

t_env	*env_free(t_env *env)
{
	ft_array_free(env, &free);
	free(env);
	return (NULL);
}

t_env	*env_new(void)
{
	t_env	*env;

	env = ft_array_new();
	if (!env)
		return (NULL);
	if (!ft_array_push(env, NULL))
		return (env_free(env));
	return (env);
}
