/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 21:11:43 by Oery              #+#    #+#             */
/*   Updated: 2026/05/05 20:07:15 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cmd.h"
#include "./exec/exec.h"
#include "src/ctx/ctx.h"
#include "src/debug/debug.h"
#include "src/parser/parser.h"
#include "src/scanner/scanner.h"

// TODO: differentiate syntax error from logic error in the parser
// > Minishell should not quit on syntax error
unsigned int	cmd_handle(const char *input, t_ctx *ctx)
{
	t_scanner	s;
	t_parser	p;
	t_cmd_node	*head;

	s = scanner_new(input);
	if (!scanner_scan(&s) || !s.tokens)
	{
		scanner_free(&s);
		return (0);
	};
	if (ctx->flags & FLAG_DEBUG)
		debug_token_list(s.tokens);
	p = parser_new(s.tokens);
	head = parser_parse(&p);
	if (ctx->flags & FLAG_DEBUG)
		debug_node(head, 0);
	track_node(head, ctx);
	scanner_free(&s);
	node_free(head);
	return (0);
}
