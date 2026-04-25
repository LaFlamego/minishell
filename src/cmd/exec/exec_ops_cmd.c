/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ops_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:08:52 by crevette          #+#    #+#             */
/*   Updated: 2026/04/25 16:41:37 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cmd.h"
#include "../tree/node.h"

unsigned int	handle_single_command(t_cmd_node *node)
{
	t_array			*cmd_node;
	unsigned int	exit_code;
	char			**args;

	cmd_node = node->data;
	args = expand_args(cmd_node->data);
	if (!args)
		return (1);
	return (cmd_exec());
}
