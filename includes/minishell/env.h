/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:15:40 by Oery              #+#    #+#             */
/*   Updated: 2026/03/15 00:16:19 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "libft/array.h"

typedef t_array	t_env;

t_env			*ft_env_new(void);
t_env			*ft_env_from(char **envp);
t_env			*ft_env_free(t_env *env);
char			*ft_env_get(t_env *env, char *key);
void			ft_env_set(t_env *env, char *key);
void			ft_env_unset(t_env *env, char *key);
void			ft_env_merge(t_env *dst, t_env *src);

#endif
