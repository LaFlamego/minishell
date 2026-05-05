/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 17:20:28 by Oery              #+#    #+#             */
/*   Updated: 2026/05/03 17:31:54 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "src/scanner/token/token.h"

void	debug_token_list(t_list *tokens)
{
	t_token	*t;
	t_list	*curr;

	ft_printf("=== TOKENS BEGIN ===\n");
	curr = tokens;
	while (curr)
	{
		t = curr->content;
		if (t->type == STRING)
			ft_printf("%s(%s) ", token_to_string(t), t->text);
		else
			ft_printf("%s ", token_to_string(t));
		curr = curr->next;
	}
	ft_printf("\n==== TOKENS END ====\n");
}
