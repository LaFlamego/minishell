/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 20:21:43 by Oery              #+#    #+#             */
/*   Updated: 2026/04/02 01:20:39 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include "src/env/env.h"

t_array		*cmd_expand_command(t_env *env, t_array *words);
t_string	*cmd_expand_dollar(t_env *env, t_string *word, size_t *i);
t_string	*cmd_expand_word(t_env *env, t_string *word);
void		*cmd_expand_wildcard(t_env *env, t_array *words);

#endif
