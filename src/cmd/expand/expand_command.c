/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 20:29:42 by Oery              #+#    #+#             */
/*   Updated: 2026/04/02 01:24:40 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./expand.h"
#include "libft.h"
#include "src/env/env.h"

static bool	is_sq_string(t_string *s)
{
	return (s->content[0] == '\'');
}

static bool	is_string(t_string *s)
{
	if (s->content[0] == '"')
		return (true);
	if (s->content[0] == '\'')
		return (true);
	return (false);
}

// TODO: Expand substitutions
// > does nested substitutions exist or are they done at the same time?
//
// TODO: Handle errors
// > How to deal with syntax errors
t_array	*cmd_expand_command(t_env *env, t_array *words)
{
	size_t		i;
	t_string	*word;
	t_array		*expanded;

	expanded = ft_array_new();
	if (!expanded)
		return (NULL);
	i = 0;
	while (i < words->size)
	{
		word = words->data[i];
		if (!is_sq_string(word))
			word = cmd_expand_word(env, word);
		if (!is_string(word) && ft_strchr(word->content, '*'))
			cmd_expand_wildcard(env, words);
		else
			ft_array_push(expanded, word);
		i++;
	}
	i = 0;
	return (expanded);
}
