/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_sq_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 19:21:12 by Oery              #+#    #+#             */
/*   Updated: 2026/04/02 01:26:01 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./tokens.h"
#include "src/cmd/lexer/lexer.h"
#include <stdlib.h>

static int	error(t_token *token, t_string *content)
{
	ft_string_free(content);
	free(token);
	return (1);
}

// Add the current char to the token and advance the lexer
static void	push_current_char(t_lexer *l, t_string *token)
{
	ft_string_push(token, l->input[l->idx]);
	l->idx++;
}

static bool	is_token_end(t_lexer *l)
{
	char	c;

	c = l->input[l->idx];
	return (c == '\0' || c == '\'');
}

// TODO: Handle push_char errors
int	tokens_sq_string(t_lexer *l, t_token *token)
{
	t_string	*s;

	s = ft_string_new(0);
	if (!s)
		return (error(token, NULL));
	push_current_char(l, s);
	while (!is_token_end(l))
	{
		push_current_char(l, s);
	}
	if (l->input[l->idx] == '\0')
	{
		// TODO: Print the syntax error, with context?
		return (error(token, s));
	}
	push_current_char(l, s);
	token->data = s->content;
	free(s);
	return (0);
}
