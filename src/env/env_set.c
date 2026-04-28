/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 18:43:28 by Oery              #+#    #+#             */
/*   Updated: 2026/04/28 21:59:36 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./env.h"
#include <stdlib.h>

// We decrease size so that the next push
// will overwrite the NULL closing the array
static char	*add_variable(t_env *env, const char *key)
{
	char	*new;

	new = ft_strdup(key);
	if (!new)
		return (NULL);
	env->size--;
	if (!ft_array_push(env, ft_strdup(key)))
		return (NULL);
	if (!ft_array_push(env, NULL))
		return (NULL);
	return (env->data[env->size - 2]);
}

/* update_variable() - update a key's value
 * @old: old key/value pair
 * @new: new key/value pair
 *
 * May or may not allocate memory depending on the old key/value pair size.
 * Does not take ownership of the new key/value pair.
 *
 * Return:
 * On success, a pointer to the new key/value pair.
 * On failure, a NULL pointer.
 */
static char	*update_variable(char **old, char *new)
{
	char	*dupe;

	if (ft_strlen(new) > ft_strlen(*old))
	{
		dupe = ft_strdup(new);
		if (!dupe)
			return (NULL);
		free(*old);
		*old = dupe;
		return (new);
	}
	else
	{
		ft_strlcpy(*old, new, ft_strlen(new) + 1);
		return (*old);
	}
}

char	*env_set(t_env *env, char *new_kvp)
{
	char	**old_kvp;

	old_kvp = env_find(env, new_kvp);
	if (old_kvp)
		return (update_variable(old_kvp, new_kvp));
	else
		return (add_variable(env, new_kvp));
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
