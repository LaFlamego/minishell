/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:06:22 by crevette          #+#    #+#             */
/*   Updated: 2026/03/09 21:11:07 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stddef.h>
#include <errno.h>

void	mini_pwd(t_ctx *ctx)
{
	char	*buf;
	size_t	size;

	size = 1024;
	buf = (char *)malloc(sizeof(char) * size);
	if (!buf)
		return ;
	
}
