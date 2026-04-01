/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:15:40 by Oery              #+#    #+#             */
/*   Updated: 2026/03/23 04:29:32 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "libft.h"

// array where each element is a char*
// KEY=VALUE
typedef t_array	t_env;

t_env			*env_new(void);
t_env			*env_from(char **envp);
t_env			*env_free(t_env *env);
char			*env_get(t_env *env, char *key);
char			**env_find(t_env *env, char *key);
void			env_set(t_env *env, char *key);
void			env_unset(t_env *env, char *key);
void			env_merge(t_env *dst, t_env *src);

int				env_set_exit_code(unsigned int exit_code, t_env *env);

#endif
