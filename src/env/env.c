/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 19:01:43 by Oery              #+#    #+#             */
/*   Updated: 2026/05/01 18:52:14 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./env.h"
#include "libft.h"
#include <stdlib.h>

char	*env_get(t_env *env, char *key)
{
	char	**var;
	char	*val;

	var = env_find(env, key);
	if (!var)
		return (NULL);
	val = ft_strchr(*var, '=');
	if (!val)
		return (NULL);
	return (val + 1);
}

t_env	*env_free(t_env *env)
{
	if (env)
		ft_array_free(env, &free);
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
