/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 15:12:39 by Oery              #+#    #+#             */
/*   Updated: 2026/04/07 15:17:14 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./token.h"
#include <stdlib.h>

t_token	*token_new(t_token_type type, char *text)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->type = type;
	token->text = text;
	return (token);
}

t_token	*token_free(t_token *token)
{
	if (!token)
		return (NULL);
	if (token->text)
		free(token->text);
	free(token);
	return (NULL);
}
