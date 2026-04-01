/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_advance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 16:16:01 by Oery              #+#    #+#             */
/*   Updated: 2026/04/02 01:26:16 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lexer.h"
#include "./tokens/tokens.h"
#include "libft.h"
#include <stdlib.h>

t_string	*ft_string_from_char(char c)
{
	t_string	*token;

	token = ft_string_new(2);
	if (!token)
		return (NULL);
	ft_string_push(token, c);
	return (token);
}

// NOTE: There cannot be 3 pipes in a row
// INFO: DQ strings should be parsed into multiple tokens probably?
// > Same for sq strings
t_token	*lexer_get_next_token(t_lexer *l)
{
	char	c;
	t_token	*token;

	c = l->input[l->idx];
	if (c == '\0')
		return (NULL);
	token = malloc(sizeof(t_token));
	if (!token)
	{
		// TODO: Handle error
		return (NULL);
	}
	token->data = NULL;
	if (c == '\'')
	{
		tokens_sq_string(l, token);
	}
	// else if (c == '"')
	// 	tokens = tokens_dq_string(l);
	else if (c == '$')
		tokens_char(l, token, DOLLAR);
	else if (c == '(')
		tokens_char(l, token, PAR_OPEN);
	else if (c == ')')
		tokens_char(l, token, PAR_CLOSE);
	else if (ft_startswith(l->input + l->idx, "&&"))
	{
		token->kind = AND;
		l->idx += 2;
	}
	else if (ft_startswith(l->input + l->idx, "||"))
	{
		token->kind = OR;
		l->idx += 2;
	}
	else if (c == '|')
		tokens_char(l, token, PIPE);
	else if (ft_isspace(c))
		tokens_blank(l, token);
	else
		tokens_ident(l, token);
	return (token);
}

int	lexer_advance(t_lexer *lex)
{
	lex->next_token = lexer_get_next_token(lex);
	return (0);
}
