/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 20:21:43 by Oery              #+#    #+#             */
/*   Updated: 2026/04/25 15:59:04 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include "src/env/env.h"

// TODO: If the result of an expansion is nothing, the argument is discarded

t_string	*cmd_expand_dollar(t_env *env, t_string *word, size_t *i);
t_string	*cmd_expand_word(t_env *env, t_string *word);
void		*cmd_expand_wildcard(t_env *env, t_array *words);

size_t		get_arg_expanded_size(t_array *tokens, t_env *env);

char		**expand_args(t_array *args);
char		*expand_redirection(t_array *tokens);

#endif
