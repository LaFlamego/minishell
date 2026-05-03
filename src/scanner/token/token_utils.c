/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 15:54:27 by Oery              #+#    #+#             */
/*   Updated: 2026/05/03 16:08:24 by Oery             ###   ########.fr       */
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

bool	token_is_redirect(t_token *t)
{
	if (t->type == REDIRECT_IN || t->type == REDIRECT_OUT)
		return (true);
	if (t->type == REDIRECT_IN_UNTIL || t->type == REDIRECT_OUT_APPEND)
		return (true);
	return (false);
}

void	token_list_debug(t_list *tokens)
{
	t_token	*t;
	t_list	*curr;

	ft_printf("=== TOKENS BEGIN ===\n");
	curr = tokens;
	while (curr)
	{
		t = curr->content;
		if (t->type == STRING)
			ft_printf("%s(%s) ", token_to_string(t), t->text);
		else
			ft_printf("%s ", token_to_string(t));
		curr = curr->next;
	}
	ft_printf("\n==== TOKENS END ====\n");
}
