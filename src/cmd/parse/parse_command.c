/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 16:20:32 by Oery              #+#    #+#             */
/*   Updated: 2026/03/22 21:58:45 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell/parse.h"

// FIRST LAYER:
//
//	Split Command into words
//	> You cannot just split spaces
//	>> "    "
//	Expand every word
// IF node was expanded > parse it's output

// FIXME: All push operations can fail and should be handled
// FIXME: We're losing quote kind

t_array	*cmd_parse_command(const char *s)
{
	size_t		i;
	t_array		*words;
	t_string	*word;

	words = ft_array_alloc();
	i = 0;
	parse_skip_whitespace(s, &i);
	while (s && s[i])
	{
		word = cmd_parse_string(s, &i);
		if (!word)
			return (NULL);
		ft_array_push(words, word);
		parse_skip_whitespace(s, &i);
	}
	return (words);
}
