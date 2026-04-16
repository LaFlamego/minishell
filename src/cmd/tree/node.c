/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:21:36 by Oery              #+#    #+#             */
/*   Updated: 2026/04/15 16:32:25 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./node.h"
#include <stdlib.h>

t_cmd_node	*node_new(enum e_kind kind)
{
	t_cmd_node	*node;

	node = malloc(sizeof(t_cmd_node));
	if (!node)
		return (NULL);
	ft_bzero(node, sizeof(t_cmd_node));
	node->kind = kind;
	if (node->kind == COMMAND)
	{
		node->data = ft_array_new();
		if (!node->data)
		{
			free(node);
			return (NULL);
		}
	}
	return (node);
}
