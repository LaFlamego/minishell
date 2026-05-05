/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 14:45:06 by Oery              #+#    #+#             */
/*   Updated: 2026/05/04 22:41:00 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./word.h"
#include <stdlib.h>

void	word_free(void *raw_word)
{
	t_word	*word;

	word = raw_word;
	ft_lstclear((t_list **)&word, &part_free);
}

t_word	*word_from(t_word_part *part)
{
	t_word	*word;

	if (!part)
		return (NULL);
	word = ft_calloc(1, sizeof(t_word));
	if (!word)
		return (NULL);
	word->content = part;
	return (word);
}
