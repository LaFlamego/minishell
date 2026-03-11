/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 18:30:12 by Oery              #+#    #+#             */
/*   Updated: 2026/03/11 18:47:15 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO: Pressing Ctrl + D add exit to the current line and run it
int	mini_exit(t_ctx *ctx)
{
	ctx->exit = true;
	return (0);
}
