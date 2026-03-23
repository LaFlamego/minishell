/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_quotes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 13:20:00 by Oery              #+#    #+#             */
/*   Updated: 2026/03/23 19:15:15 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	is_a_string(const t_string *word)
{
	char	c;

	if (word->size <= 2)
		return (false);
	c = word->content[0];
	if (c == '\'' || c == '\"')
		return (true);
	return (false);
}

static void	remove_quote_in(t_string *word)
{
	ft_string_pop(word, word->content);
	word->content[word->size - 2] = '\0';
	word->size--;
}

void	cmd_quotes_remove(const t_array *words)
{
	size_t		i;
	t_string	*word;

	i = 0;
	while (i < words->size)
	{
		word = words->data[i];
		if (is_a_string(word))
			remove_quote_in(word);
		i++;
	}
}
