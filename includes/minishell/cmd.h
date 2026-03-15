/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:50:13 by Oery              #+#    #+#             */
/*   Updated: 2026/03/15 00:51:55 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include "libft/array.h"
# include "minishell/env.h"

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
}			t_kind;

struct		s_node
{
	t_kind	kind;
	void	*data;
};

t_array		*cmd_parse(const char *s);
t_array		*cmd_expand(t_env *env, t_array *words);

#endif
