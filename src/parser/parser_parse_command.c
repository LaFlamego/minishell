/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 16:16:02 by Oery              #+#    #+#             */
/*   Updated: 2026/04/25 15:30:20 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"
#include <stdlib.h>

t_cmd_node	*init_node(void)
{
	t_cmd_node	*node;

	node = node_new(COMMAND);
	if (!node)
		return (NULL);
	node->data = ft_array_new();
	if (!node->data)
	{
		free(node);
		return (NULL);
	}
	return (node);
}

t_cmd_node	*parser_parse_command(t_parser *p)
{
	t_token		*t;
	t_cmd_node	*node;
	t_cmd_args	*data;

	node = node_new(COMMAND);
	if (!node)
		return (NULL);
	data = node->data;
	if (!ft_array_push(&data->args, parser_previous(p)))
		return (NULL);
	while (parser_match_command(p))
	{
		t = parser_previous(p);
		if (t->type != BLANK && !ft_array_push(&data->args, t))
			return (NULL);
	}
	return (node);
}
