/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:50:13 by Oery              #+#    #+#             */
/*   Updated: 2026/03/13 21:56:28 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

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

void		cmd_parse(char *input);

#endif
