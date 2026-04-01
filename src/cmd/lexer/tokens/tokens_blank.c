/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_blank.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 20:59:20 by Oery              #+#    #+#             */
/*   Updated: 2026/04/02 01:25:17 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./tokens.h"

int	tokens_blank(t_lexer *l, t_token *token)
{
	token->kind = BLANK;
	while (l->input[l->idx] && ft_isspace(l->input[l->idx]))
		l->idx++;
	return (0);
}
