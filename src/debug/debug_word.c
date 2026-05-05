/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 17:35:02 by Oery              #+#    #+#             */
/*   Updated: 2026/05/05 01:11:59 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./debug.h"

void	debug_part(t_word_part *part, size_t depth)
{
	if (part->kind == WK_STRING)
	{
		debug_node_string(part, depth, "> STRING\n");
	}
	if (part->kind == WK_VARIABLE)
	{
		debug_node_string(part, depth, "> VARIABLE\n");
	}
	if (part->kind == WK_FILES)
	{
		debug_indent(depth);
		ft_printf("> FILES\n");
	}
	if (part->kind >= WK_REDIRECT_IN && part->kind <= WK_REDIRECT_OUT_APPEND)
		debug_node_redirect(part, depth);
}

void	debug_words(t_list *parts, size_t depth)
{
	t_list	*curr;

	debug_indent(depth);
	ft_printf("> WORD\n");
	curr = parts;
	while (curr)
	{
		debug_part(curr->content, depth + 1);
		curr = curr->next;
	}
}
