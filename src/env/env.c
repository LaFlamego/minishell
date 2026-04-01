/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 19:01:43 by Oery              #+#    #+#             */
/*   Updated: 2026/04/02 01:18:54 by Oery             ###   ########.fr       */
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

// TODO: Push can fail, so ft_env_set should return an error
void	env_set(t_env *env, char *key)
{
	char	**var;
	char	*value;
	char	*new_str;
	size_t	i;

	var = env_find(env, key);
	if (var)
	{
		value = ft_strchr(key, '=');
		if (value && (ft_strlen(value) <= ft_strlen(*var)))
		{
			ft_strlcpy(*var, key, ft_strlen(key) + 1);
		}
		else
		{
			i = var - (char **)env->data;
			if (!value && ft_strchr(env->data[i], '='))
				return ;
			new_str = ft_strdup(key);
			if (!new_str)
				return ;
			free(env->data[i]);
			env->data[i] = new_str;
		}
	}
	else
	{
		env->size--;
		ft_array_push(env, ft_strdup(key));
		ft_array_push(env, NULL);
	}
}

void	env_unset(t_env *env, char *key)
{
	void	**var;
	size_t	i;

	var = (void **)env_find(env, key);
	if (var)
	{
		i = var - env->data;
		free(env->data[i]);
		ft_array_pop(env, var);
	}
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
