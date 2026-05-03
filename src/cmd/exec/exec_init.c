/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 10:13:53 by crevette          #+#    #+#             */
/*   Updated: 2026/05/03 16:54:34 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "libft.h"

void    init_exec_ctx(t_exec_ctx *exec)
{
    ft_bzero(exec, sizeof(t_exec_ctx));
    exec->cmd.path = NULL;
	exec->fd.in = -1;
	exec->fd.out = -1;
	exec->pipe.fd = -1;
	exec->pipe.index = 0;
}