/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 16:06:31 by Oery              #+#    #+#             */
/*   Updated: 2026/04/02 01:26:53 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"

t_parser	parser_new(const char *input)
{
	t_parser	parser;

	parser.lex = lexer_new(input);
	parser.tree = NULL;
	return (parser);
}
