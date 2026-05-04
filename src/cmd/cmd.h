/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:50:13 by Oery              #+#    #+#             */
/*   Updated: 2026/05/04 18:23:43 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include "libft.h"
# include "src/ctx/ctx.h"

bool				is_sq_string(t_string *s);
unsigned int		cmd_handle(const char *input, t_ctx *ctx);
void				cmd_quotes_remove(const t_array *words);

#endif
