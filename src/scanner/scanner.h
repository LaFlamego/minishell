/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 16:54:48 by Oery              #+#    #+#             */
/*   Updated: 2026/04/09 16:26:31 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCANNER_H
# define SCANNER_H

# include "./token/token.h"
# include "libft.h"

/**
 * struct s_scanner - lexical scanner state
 * @source: input source buffer (null-terminated, not owned)
 * @tokens: token output array
 * @current: current cursor position in source
 * @start: start of current lexeme
 */
typedef struct s_scanner
{
	const char	*source;
	t_array		tokens;
	size_t		current;
	size_t		start;
}				t_scanner;

t_scanner		scanner_new(const char *source);
char			scanner_advance(t_scanner *s);
t_array			*scanner_scan(t_scanner *s);
char			scanner_peek(t_scanner *s);
char			scanner_peek_next(t_scanner *s);
bool			scanner_match(t_scanner *s, char expected);
void			*scanner_error(t_scanner *s, char expected, size_t current);
t_token			*scanner_add_token(t_scanner *s, t_token_type type);
t_token			*scanner_add_token_lit(t_scanner *s, t_token_type type,
					char *text);

t_token			*token_scan(t_scanner *s);
t_token			*token_scan_ident(t_scanner *s);
t_token			*token_scan_string(t_scanner *s);

bool			is_valid_ident(const char c);

#endif
