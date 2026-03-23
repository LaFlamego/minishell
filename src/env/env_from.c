/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_from.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 04:30:09 by Oery              #+#    #+#             */
/*   Updated: 2026/03/23 04:30:18 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/env.h"

t_env	*env_from(char **envp)
{
	t_env	*env;
	size_t	i;

	env = ft_array_new();
	if (!env)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		if (!ft_array_push(env, ft_strdup(envp[i])))
			return (env_free(env));
		if (!env->data[i])
			return (env_free(env));
		i++;
	}
	if (!ft_array_push(env, NULL))
		return (env_free(env));
	return (env);
}
