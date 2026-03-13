/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 19:01:43 by Oery              #+#    #+#             */
/*   Updated: 2026/03/13 17:52:16 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell/env.h"
#include <stdlib.h>

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

char	**ft_env_find(t_env *env, char *key)
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

void	*ft_env_get(t_env *env, char *key)
{
	char	**var;

	var = ft_env_find(env, key);
	if (!var)
		return (NULL);
	return (ft_strchr(*var, '=') + 1);
}

// TODO: Push can fail, so ft_env_set should return an error
void	ft_env_set(t_env *env, char *key)
{
	char	**var;
	char	*value;
	char	*new_str;
	size_t	i;

	var = ft_env_find(env, key);
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

void	ft_env_unset(t_env *env, char *key)
{
	void	**var;
	size_t	i;

	var = (void **)ft_env_find(env, key);
	if (var)
	{
		i = var - env->data;
		free(env->data[i]);
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

// Merge two environments. If a key is in both, the one in DST will be kept.
// FIXME: ft_env_set will return an error
void	ft_env_merge(t_env *dst, t_env *src)
{
	size_t	i;
	char	*key;

	i = 0;
	while (i < src->size - 1)
	{
		key = src->data[i];
		if (!ft_env_find(dst, key))
		{
			if (ft_strchr(key, '='))
				ft_env_set(dst, key);
		}
		i++;
	}
}
