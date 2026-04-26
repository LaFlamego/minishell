/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 14:09:13 by Oery              #+#    #+#             */
/*   Updated: 2026/04/26 18:42:44 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"
#include "libft.h"

// TODO: Should it be printed to stderr?
void	*parser_error(t_token *t)
{
	char	*text;

	if (t->type == STRING)
		text = t->text;
	else
		text = token_to_string(t);
	ft_dprintf(2, "minishell: syntax error near unexpected token `%s'\n", text);
	return (NULL);
}
