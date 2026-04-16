/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 10:13:53 by crevette          #+#    #+#             */
/*   Updated: 2026/04/16 10:18:35 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

void    init_cmd(t_cmd *cmd)
{
    ft_bzero(cmd, sizeof(t_cmd));
    cmd->path = NULL;
    cmd->cmds = NULL;
    cmd->valid = false;
    cmd->f_no_x = false;
    cmd->is_path = false;
}