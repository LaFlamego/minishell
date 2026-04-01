/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 16:19:00 by Oery              #+#    #+#             */
/*   Updated: 2026/04/02 01:26:12 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lexer.h"

t_lexer	lexer_new(const char *input)
{
	t_lexer	lex;

	lex.input = input;
	lex.idx = 0;
	lex.next_token = NULL;
	return (lex);
}
