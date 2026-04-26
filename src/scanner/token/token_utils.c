/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 15:54:27 by Oery              #+#    #+#             */
/*   Updated: 2026/04/26 16:00:07 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./token.h"
#include "src/cmd/tree/node.h"

// Return value should not be freed
char	*token_to_string(t_token *token)
{
	if (token->type == LEFT_PAREN)
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
	else if (token->type == REDIRECT_IN)
		return ("<");
	else if (token->type == REDIRECT_IN_UNTIL)
		return ("<<");
	else if (token->type == REDIRECT_OUT)
		return (">");
	else if (token->type == REDIRECT_OUT_APPEND)
		return (">>");
	else
		return ("UNKNOWN_TOKEN");
}

// TODO: Add Redirections
// enum e_kind	token_tokind(t_token *t)
// {
// 	if (t->type == AND)
// 		return (OP_AND);
// 	if (t->type == OR)
// 		return (OP_OR);
// 	if (t->type == PIPE)
// 		return (PIPELINE);
// 	if (t->type == REDIRECT_IN)
// 		return (W_REDIRECT_IN);
// 	if (t->type == REDIRECT_IN_UNTIL)
// 		return (W_REDIRECT_IN_UNTIL);
// 	if (t->type == REDIRECT_OUT)
// 		return (W_REDIRECT_OUT);
// 	if (t->type == REDIRECT_OUT_APPEND)
// 		return (W_REDIRECT_OUT_APPEND);
// 	if (t->type == STAR)
// 		return (W_FILES);
// 	if (t->type == DOLLAR)
// 		return (W_VARIABLE);
// 	ft_printf("token_tokind is missing this operator!\n");
// 	return (0);
// }

bool	token_is_redirect(t_token *t)
{
	if (t->type == REDIRECT_IN || t->type == REDIRECT_OUT)
		return (true);
	if (t->type == REDIRECT_IN_UNTIL || t->type == REDIRECT_OUT_APPEND)
		return (true);
	return (false);
}
