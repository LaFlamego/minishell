/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner_add_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 23:45:40 by Oery              #+#    #+#             */
/*   Updated: 2026/04/22 15:45:46 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./scanner.h"
#include "./token/token.h"
#include <stdlib.h>

t_token	*scanner_add_token(t_scanner *s, t_token_type type)
{
	t_token	*token;

	token = token_new(type, NULL);
	if (!token || !ft_array_push(&s->tokens, token))
	{
		token_free(token);
		return (NULL);
	}
	return (token);
}

t_token	*scanner_add_token_lit(t_scanner *s, t_token_type type, char *text)
{
	t_token	*token;

	token = token_new(type, text);
	if (!token || !token->text || !ft_array_push(&s->tokens, token))
	{
		token_free(token);
		return (NULL);
	}
	return (token);
}
