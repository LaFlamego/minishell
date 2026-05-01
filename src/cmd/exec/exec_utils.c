/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:37:56 by crevette          #+#    #+#             */
/*   Updated: 2026/05/01 21:28:42 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../cmd.h"

void	pipe_build(int *pipe_in, int *pipe_out)
{
	int	pipefd[2];

	if (pipe(pipefd) == -1)
		perror("pipe");
	*pipe_in = pipefd[0];
	*pipe_out = pipefd[1];
}

void	free_cmd_path(t_exec_ctx *exec)
{
	if (exec->cmd.path == NULL)
		return ;
	free(exec->cmd.path);
	exec->cmd.path = NULL;
}
