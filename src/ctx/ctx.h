/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 18:29:55 by Oery              #+#    #+#             */
/*   Updated: 2026/04/02 01:17:30 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CTX_H
# define CTX_H

# include "src/env/env.h"

typedef struct s_ctx
{
	t_env	*env;
	bool	exit;
}			t_ctx;

void		ctx_init(t_ctx *ctx, char **envp);

#endif
