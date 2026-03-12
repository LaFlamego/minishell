/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 18:30:12 by Oery              #+#    #+#             */
/*   Updated: 2026/03/12 15:20:49 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO: Exit Code of mini_exit should be
// > the same as the one of the last executed command
// > N if mini_exit has 1 argument

int	mini_exit(t_ctx *ctx)
{
	ctx->exit = true;
	return (0);
}
