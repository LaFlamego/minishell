/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 20:33:08 by Oery              #+#    #+#             */
/*   Updated: 2026/03/23 04:26:58 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell/env.h"
#include <stdlib.h>

// FIXME: Single $ should stay a single dollar sign
// Maybe handle substitutions as separated Nodes ?
// Then each node would have an array of subnodes.
// Would process to a final node
//
// NOTE: Flow
// 1. Create a new array of word
// 2. Build the current string char by char
// 3. If '$', push the current string and read the key, then push the result
// 4. Concatenate the strings back to a single string
//

// FIXME: Allocation can fail
// > needs to be handled
// > "?" is a valid key and should be readable
// FIXME: ft_isalnum is not correct and will reject $? as a valid key
// FIXME: ft_string_push can fail
// TODO: Start + 1 is confusing, find a better way to skip the $ sign
static t_string	*read_key(t_string *word, size_t start)
{
	size_t		i;
	t_string	*key;

	key = ft_string_new(0);
	if (!key)
		return (NULL);
	i = start + 1;
	while (i < word->size && ft_isalnum(word->content[i]))
	{
		if (!ft_string_push(key, word->content[i]))
		{
			ft_string_free(key);
			free(key);
			return (NULL);
		}
		i++;
	}
	return (key);
}

// TODO: read_key must be able to return an error
t_string	*cmd_expand_dollar(t_env *env, t_string *word, size_t *i)
{
	char		*val;
	t_string	*key;
	t_string	*expanded;

	expanded = ft_string_new(0);
	if (!expanded)
		return (NULL);
	key = read_key(word, *i);
	if (!key)
	{
		ft_string_free(expanded);
		free(expanded);
		return (NULL);
	}
	*i += key->size - 1;
	if (!key->content)
		ft_string_push(expanded, '$');
	else
	{
		val = env_get(env, key->content);
		if (val)
		{
			ft_string_push_str(expanded, val);
		}
	}
	ft_string_free(key);
	return (expanded);
}
