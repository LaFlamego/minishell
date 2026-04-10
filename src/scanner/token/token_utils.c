/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 15:54:27 by Oery              #+#    #+#             */
/*   Updated: 2026/04/10 14:58:24 by Oery             ###   ########.fr       */
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
	else if (token->type == STRING)
		ft_printf("STRING %d -> \"%s\"\n", ft_strlen(token->text), token->text);
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
	else if (token->type == REDIRECT_IN)
		ft_printf("REDIRECT_IN\n");
	else if (token->type == REDIRECT_IN_UNTIL)
		ft_printf("REDIRECT_IN_UNTIL\n");
	else if (token->type == REDIRECT_OUT)
		ft_printf("REDIRECT_OUT\n");
	else if (token->type == REDIRECT_OUT_APPEND)
		ft_printf("REDIRECT_OUT_APPEND\n");
	else
		ft_printf("UNKNOWN TOKEN\n");
}
