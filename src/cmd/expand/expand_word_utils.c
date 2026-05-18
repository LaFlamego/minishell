/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_word_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 23:53:57 by Oery              #+#    #+#             */
/*   Updated: 2026/05/18 23:55:26 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "src/cmd/tree/word/word.h"

bool	has_string(t_list *parts)
{
	t_list		*curr;
	t_word_part	*part;

	curr = parts;
	while (curr)
	{
		part = curr->content;
		if (part->kind == WK_STRING)
			return (true);
		curr = curr->next;
	}
	return (false);
}

bool	is_file_list(t_list *parts)
{
	t_list		*curr;
	t_word_part	*part;
	bool		has_wildcard;

	has_wildcard = false;
	curr = parts;
	while (curr)
	{
		part = curr->content;
		if (part->kind == WK_VARIABLE)
			return (false);
		if (part->kind == WK_FILES)
			has_wildcard = true;
		curr = curr->next;
	}
	return (has_wildcard);
}
