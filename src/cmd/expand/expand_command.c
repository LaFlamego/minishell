/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 20:29:42 by Oery              #+#    #+#             */
/*   Updated: 2026/03/22 20:40:54 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell/env.h"
#include "minishell/expand.h"

static bool	has_substitutions(const t_string *word)
{
	return (ft_strchr(word->content, '$'));
}

static bool	is_sq_string(t_string *s)
{
	return (s->content[0] == '\'');
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

	i = 0;
	while (i < words->size)
	{
		word = words->data[i];
		if (!is_sq_string(word) && has_substitutions(word))
			words->data[i] = cmd_expand_word(env, word);
		i++;
	}
	i = 0;
	return (words);
}
