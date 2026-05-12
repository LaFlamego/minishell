/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 15:54:27 by Oery              #+#    #+#             */
/*   Updated: 2026/05/12 20:11:25 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./token.h"

static char	*token_to_string_redirection(t_token *token)
{
	if (token->type == REDIRECT_IN)
		return ("<");
	else if (token->type == REDIRECT_IN_UNTIL)
		return ("<<");
	else if (token->type == REDIRECT_OUT)
		return (">");
	else if (token->type == REDIRECT_OUT_APPEND)
		return (">>");
	return (NULL);
}

// Return value should not be freed
char	*token_to_string(t_token *token)
{
	if (token->type >= REDIRECT_IN && token->type <= REDIRECT_OUT_APPEND)
		return (token_to_string_redirection(token));
	else if (token->type == LEFT_PAREN)
		return ("(");
	else if (token->type == RIGHT_PAREN)
		return (")");
	else if (token->type == DOLLAR)
		return ("$");
	else if (token->type == STAR)
		return ("*");
	else if (token->type == STRING)
		return ("STRING");
	else if (token->type == OR)
		return ("||");
	else if (token->type == AND)
		return ("&&");
	else if (token->type == PIPE)
		return ("|");
	else if (token->type == EOF)
		return ("EOF");
	else if (token->type == BLANK)
		return ("BLANK");
	else
		return ("UNKNOWN_TOKEN");
}
