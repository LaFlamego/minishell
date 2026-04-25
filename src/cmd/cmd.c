/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 21:11:43 by Oery              #+#    #+#             */
/*   Updated: 2026/04/25 18:18:20 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cmd.h"
#include "src/ctx/ctx.h"
#include "src/parser/parser.h"
#include "src/scanner/scanner.h"

static void	debug_tokens(t_list *tokens)
{
	t_list	*curr;

	curr = tokens;
	while (curr)
	{
		ft_printf("%s\n", token_to_string(curr->content));
		curr = curr->next;
	}
}

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
	if (!s.tokens)
	{
		// TODO: handle error
	}
	debug_tokens(s.tokens);
	p = parser_new(s.tokens);
	head = parser_parse(&p);
	ft_printf("head -> %p\n", head);
	ft_printf("Head Kind -> %d\n", head->kind);
	// ft_printf("Args size -> %d\n", node->args.size);
	node_debug(head, 0);
	(void)ctx;
	return (0);
}
