/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_ident.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 20:32:18 by Oery              #+#    #+#             */
/*   Updated: 2026/04/02 01:25:48 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/cmd/lexer/lexer.h"

static bool	is_new_token(char c)
{
	if (ft_isspace(c))
		return (true);
	if (c == '$')
		return (true);
	if (c == '"' || c == '\'')
		return (true);
	return (false);
}

t_string	*tokens_ident(t_lexer *l)
{
	char		c;
	t_string	*token;

	token = ft_string_new(0);
	if (!token)
		return (NULL);
	c = l->input[l->idx];
	while (c && !is_new_token(c))
	{
		ft_string_push(token, c);
		l->idx++;
	}
	return (token);
}
