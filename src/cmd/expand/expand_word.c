/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 20:20:54 by Oery              #+#    #+#             */
/*   Updated: 2026/04/17 17:22:02 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./expand.h"
#include "libft.h"
#include "src/env/env.h"

// NOTE: How old is this?

// FIXME: expand_dollar can fail
// FIXME: push can fail
// TODO: This needs to be able to return an exit code
t_string	*cmd_expand_word(t_env *env, t_string *word)
{
	size_t		i;
	t_array		parts;
	t_string	*curr;
	t_string	*final_word;
	t_string	*expanded;

	parts = ft_array_init();
	curr = ft_string_new(0);
	if (!curr)
		return (NULL);
	i = 0;
	while (i < word->size)
	{
		if (word->content[i] == '$')
		{
			if (curr->size > 0)
				ft_array_push(&parts, curr);
			curr = ft_string_new(0);
			if (!curr)
			{
				// TODO: Handle errors
			}
			expanded = cmd_expand_dollar(env, word, &i);
			// only push if expanded has something
			if (expanded->size > 0)
				ft_array_push(&parts, expanded);
			// free expanded
		}
		else
		{
			ft_string_push(curr, word->content[i]);
		}
		i++;
	}
	if (curr->size > 0)
		// TODO: Curr must have a value here
		ft_array_push(&parts, curr);
	final_word = ft_string_join(&parts);
	// TODO: Join can fail
	ft_array_foreach(&parts, &ft_string_free);
	return (final_word);
}
