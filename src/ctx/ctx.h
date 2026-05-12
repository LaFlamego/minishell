/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 18:29:55 by Oery              #+#    #+#             */
/*   Updated: 2026/05/12 21:04:02 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CTX_H
# define CTX_H

# include "src/env/env.h"

// TODO: does that mean we have to handle non interactive mode?
# define FLAG_CLI_MODE 1
# define FLAG_DEBUG 2

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
