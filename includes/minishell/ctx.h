/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 18:29:55 by Oery              #+#    #+#             */
/*   Updated: 2026/03/22 21:30:30 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CTX_H
# define CTX_H

# include "minishell/env.h"

typedef struct s_ctx
{
	t_env	*env;
	bool	exit;
}			t_ctx;

void		ctx_init(t_ctx *ctx, char **envp);

#endif
