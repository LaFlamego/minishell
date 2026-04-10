/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 15:13:14 by Oery              #+#    #+#             */
/*   Updated: 2026/04/10 19:56:01 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

// TODO: Add Redirections
// TODO: Blank spaces have meaning and should store their content
typedef enum e_token_type
{
	LEFT_PAREN,
	RIGHT_PAREN,
	DOLLAR,
	STAR,
	BLANK,
	STRING,
	AND,
	OR,
	PIPE,
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
t_token				*token_free(t_token *token);

void				token_debug(t_token *token);

#endif
