/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:50:13 by Oery              #+#    #+#             */
/*   Updated: 2026/03/23 19:07:42 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include "libft.h"
# include "minishell/ctx.h"

// TODO: Add bonuses
typedef enum s_kind
{
	STRING,
	INSERT_CMD,
	INSERT_ENV_VAR,
	REDIRECT_INPUT,
	REDIRECT_OUTPUT,
	READ_UNTIL,
	REDIRECT_APPEND,
	PIPE,
}				t_kind;

struct			s_node
{
	t_kind		kind;
	void		*data;
};

bool			is_sq_string(t_string *s);
unsigned int	cmd_handle(const char *input, t_ctx *ctx);
void			cmd_quotes_remove(const t_array *words);

#endif
