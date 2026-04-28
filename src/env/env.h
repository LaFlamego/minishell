/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:15:40 by Oery              #+#    #+#             */
/*   Updated: 2026/04/28 21:48:07 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "libft.h"

// array where each element is a char*
// KEY=VALUE
typedef t_array	t_env;

/**
 * env_new() - instantiate a new environment
 *
 * Return:
 * On success, a pointer to the new environment
 * On failure, a NULL pointer
 */
t_env			*env_new(void);

t_env			*env_from(char **envp);

/**
 * env_free() - clean and free an environment
 * @env: the environment to free
 *
 * Return:
 * A NULL pointer
 */
t_env			*env_free(t_env *env);

/**
 * env_get() - get a value from a pair
 * @env - an environment
 * @key - the key of the target value
 *
 * Return:
 * char *value if the key is found
 * NULL if not
 */
char			*env_get(t_env *env, char *key);
char			**env_find(t_env *env, const char *key);

/**
 * env_set() - set a variable
 * @env: the target environment
 * @kvp: a key/value pair as string (ex: "KEY=VALUE")
 *
 * Set a new variable if the key doesn't exist in the environment.
 * Otherwise, update the key/value pair otherwise.
 *
 * Return:
 * On success, a pointer to new key/value pair
 * On failure, a NULL pointer
 */
char			*env_set(t_env *env, char *kvp);

void			env_unset(t_env *env, char *key);
void			env_merge(t_env *dst, t_env *src);

int				env_set_exit_code(unsigned int exit_code, t_env *env);

#endif
