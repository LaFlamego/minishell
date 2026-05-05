/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_part.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 19:38:42 by Oery              #+#    #+#             */
/*   Updated: 2026/05/04 19:40:02 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./word.h"
#include <stdlib.h>

t_word_part	*part_new(t_word_kind kind, void *content)
{
	t_word_part	*part;

	part = ft_calloc(1, sizeof(t_word_part));
	if (part)
	{
		part->kind = kind;
		part->data = content;
	}
	return (part);
}

/*
 * part_free() - free a `t_word_part`
 *
 * doesn't free WK_STRING's content as it's owned by the `t_token`
 */
void	part_free(void *raw_part)
{
	t_word_part	*part;

	if (!raw_part)
		return ;
	part = raw_part;
	if (!part->data)
	{
		free(part);
		return ;
	}
	if (part->kind == WK_STRING || part->kind == WK_VARIABLE)
	{
		// TODO: free(part->data);
	}
	if (part->kind == WK_REDIRECT_IN || part->kind == WK_REDIRECT_IN_UNTIL)
		part_free(part->data);
	if (part->kind == WK_REDIRECT_OUT || part->kind == WK_REDIRECT_OUT_APPEND)
		part_free(part->data);
	free(part);
}
