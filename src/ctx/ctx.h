/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 18:29:55 by Oery              #+#    #+#             */
/*   Updated: 2026/05/16 20:47:10 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CTX_H
# define CTX_H

# include "src/env/env.h"

# define FLAG_DEBUG 1

typedef struct s_ctx
{
	t_env	*env;
	bool	exit;
	int		flags;
	char	*command;
}			t_ctx;

int			ctx_init(t_ctx *ctx, char **envp);
int			ctx_free(t_ctx *ctx);

#endif
