/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 18:30:12 by Oery              #+#    #+#             */
/*   Updated: 2026/03/11 19:32:17 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO: Exit Code of mini_exit should be
// > the same as the one of the last executed command

// TODO: Pressing Ctrl + D add exit to the current line and run it
int	mini_exit(t_ctx *ctx)
{
	ctx->exit = true;
	return (0);
}
