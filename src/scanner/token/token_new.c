/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 15:12:39 by Oery              #+#    #+#             */
/*   Updated: 2026/04/17 16:49:48 by Oery             ###   ########.fr       */
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

void	token_free(void *token_raw)
{
	t_token	*token;

	token = token_raw;
	if (!token)
		return ;
	if (token->text)
		free(token->text);
	free(token);
}
