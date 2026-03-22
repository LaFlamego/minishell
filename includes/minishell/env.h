/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:15:40 by Oery              #+#    #+#             */
/*   Updated: 2026/03/22 21:20:49 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "libft.h"

// array where each element is a char*
// KEY=VALUE
typedef t_array	t_env;

t_env			*ft_env_new(void);
t_env			*ft_env_from(char **envp);
t_env			*ft_env_free(t_env *env);
char			*ft_env_get(t_env *env, char *key);
void			ft_env_set(t_env *env, char *key);
void			ft_env_unset(t_env *env, char *key);
void			ft_env_merge(t_env *dst, t_env *src);

int				ft_env_set_exit_code(unsigned int exit_code, t_env *env);

#endif
