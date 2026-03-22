/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 16:19:44 by Oery              #+#    #+#             */
/*   Updated: 2026/03/22 20:37:13 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "libft.h"

t_array		*cmd_parse_command(const char *s);
t_string	*cmd_parse_string(const char *s, size_t *i);
void		parse_skip_whitespace(const char *s, size_t *i);

#endif
