/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 15:13:14 by Oery              #+#    #+#             */
/*   Updated: 2026/04/26 00:43:21 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include <stdbool.h>

typedef enum e_token_type
{
	LEFT_PAREN,
	RIGHT_PAREN,
	BLANK,
	AND,
	OR,
	PIPE,
	STRING,
	DOLLAR,
	STAR,
	REDIRECT_IN,
	REDIRECT_IN_UNTIL,
	REDIRECT_OUT,
	REDIRECT_OUT_APPEND,
	EOF,
}					t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*text;
}					t_token;

t_token				*token_new(t_token_type type, char *text);
void				token_free(void *token_raw);

char				*token_to_string(t_token *token);
void				token_debug(t_token *token);

bool				token_is_redirect(t_token *token);

#endif
