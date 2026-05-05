/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_node_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 17:16:38 by Oery              #+#    #+#             */
/*   Updated: 2026/05/03 17:19:54 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "src/cmd/tree/word/word.h"

void	debug_indent(size_t lvl)
{
	size_t	i;

	i = 0;
	while (i < lvl)
	{
		ft_printf("    ");
		i++;
	}
}

void	debug_node_string(t_word_part *part, size_t depth, char *text)
{
	debug_indent(depth);
	ft_printf(text);
	debug_indent(depth);
	ft_printf("== Value: %s\n", part->data);
}
