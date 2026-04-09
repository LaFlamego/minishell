/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 15:54:27 by Oery              #+#    #+#             */
/*   Updated: 2026/04/09 16:42:04 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./token.h"
#include "libft.h"

void	token_debug(t_token *token)
{
	if (token->type == LEFT_PAREN)
		ft_printf("LEFT_PAREN\n");
	else if (token->type == RIGHT_PAREN)
		ft_printf("RIGHT_PAREN\n");
	else if (token->type == DOLLAR)
		ft_printf("DOLLAR\n");
	else if (token->type == STAR)
		ft_printf("STAR\n");
	else if (token->type == LEFT_BRACE)
		ft_printf("LEFT_BRACE\n");
	else if (token->type == RIGHT_BRACE)
		ft_printf("RIGHT_BRACE\n");
	else if (token->type == IDENT)
		ft_printf("IDENT -> %s\n", token->text);
	else if (token->type == STRING)
		ft_printf("STRING -> %s\n", token->text);
	else if (token->type == OR)
		ft_printf("OR\n");
	else if (token->type == AND)
		ft_printf("AND\n");
	else if (token->type == PIPE)
		ft_printf("PIPE\n");
	else if (token->type == EOF)
		ft_printf("EOF\n");
	else if (token->type == BLANK)
		ft_printf("BLANK\n");
	else
		ft_printf("UNKNOWN TOKEN\n");
}
