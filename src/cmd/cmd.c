/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 21:11:43 by Oery              #+#    #+#             */
/*   Updated: 2026/04/17 12:29:21 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cmd.h"
#include "src/ctx/ctx.h"
#include "src/parser/parser.h"
#include "src/scanner/scanner.h"

static void	debug_tokens(t_array *tokens)
{
	size_t	i;

	i = 0;
	while (i < tokens->size)
	{
		token_debug(tokens->data[i]);
		i++;
	}
}

// TODO: AST
// 1. Tokenize the command (is this necessary?)
// 2. Turn it into statements / command

// TODO: Parse Input as a tree
// > words must be an array of cmds, linked with an operator

// TODO: Free Resources after the command ran
unsigned int	cmd_handle(const char *input, t_ctx *ctx)
{
	t_scanner	s;
	t_parser	p;
	t_cmd_node	*head;

	s = scanner_new(input);
	if (!scanner_scan(&s))
	{
		scanner_free(&s);
		return (1);
	};
	debug_tokens(&s.tokens);
	p = parser_new(&s.tokens);
	head = parser_parse_node(&p);
	ft_printf("Head = %p\n", head);
	node_debug(head);
	(void)ctx;
	return (0);
}
