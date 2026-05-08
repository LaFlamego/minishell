/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 14:09:13 by Oery              #+#    #+#             */
/*   Updated: 2026/05/08 19:52:08 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"
#include "libft.h"

void	*parser_error(t_parser *p, t_token *t)
{
	char	*text;

	while (p->current && p->current->next)
		p->current = p->current->next;
	if (t->type == STRING)
		text = t->text;
	else
		text = token_to_string(t);
	ft_dprintf(2, "minishell: syntax error near unexpected token `%s'\n", text);
	return (NULL);
}
