/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 19:01:43 by Oery              #+#    #+#             */
/*   Updated: 2026/03/11 20:42:16 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include "src/array/ft_array.h"
#include <stddef.h>

bool	is_key(char *var, char *key)
{
	char	*sep;

	if (!var)
		return (false);
	sep = ft_strchr(var, '=');
	return (ft_strncmp(var, key, sep - var) == 0);
}

void	*ft_env_find(t_env *env, char *key)
{
	size_t	i;

	i = 0;
	while (i < env->size)
	{
		if (is_key(env->data[i], key))
			return (env->data + i);
		i++;
	}
	return (NULL);
}

void	*ft_env_get(t_env *env, char *key)
{
	char	*var;

	var = ft_env_find(env, key);
	if (!var)
		return (NULL);
	return (ft_strchr(var, '=') + 1);
}

// TODO:
// FIXME: If we push a new variable, then the last value won't be NULL
// > We need to replace the last one, then push NULL
// TODO: Push can fail, so ft_env_set should return an error
void	ft_env_set(t_env *env, char *key, char *value)
{
	char	*var;
	char	*new_str;
	size_t	i;

	var = ft_env_find(env, key);
	if (var)
	{
		if (ft_strlen(value) <= ft_strlen(var))
		{
			ft_strlcpy(var, value, ft_strlen(value));
		}
		else
		{
			new_str = ft_strdup(key);
			if (!new_str)
				return ;
			free(var);
			i = var - (char *)env->data;
			env->data[i] = new_str;
		}
	}
	else
	{
		// Get Key Size,
		// Get Value Size,
		// Allocate String
		// Concatenate it
		// Insert it
		env->size--;
		ft_array_push(env, ft_strdup(key));
		ft_array_push(env, NULL);
	}
}

void	ft_env_unset(t_env *env, char *key)
{
	void	*var;

	var = ft_env_find(env, key);
	if (var)
	{
		free(*(void **)var);
		ft_array_pop(env, var);
	}
}

t_env	*ft_env_free(t_env *env)
{
	ft_array_free(env, &free);
	free(env);
	return (NULL);
}

t_env	*ft_env_new(void)
{
	t_env	*env;

	env = ft_array_alloc();
	if (!env)
		return (NULL);
	if (!ft_array_push(env, NULL))
		return (ft_env_free(env));
	return (env);
}

t_env	*ft_env_from(char **envp)
{
	t_env	*env;
	size_t	i;

	env = ft_array_alloc();
	if (!env)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		if (!ft_array_push(env, ft_strdup(envp[i])))
			return (ft_env_free(env));
		if (!env->data[i])
			return (ft_env_free(env));
		i++;
	}
	if (!ft_array_push(env, NULL))
		return (ft_env_free(env));
	return (env);
}
