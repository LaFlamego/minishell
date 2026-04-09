/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 15:13:14 by Oery              #+#    #+#             */
/*   Updated: 2026/04/09 16:13:49 by Oery             ###   ########.fr       */
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
	LEFT_BRACE,
	RIGHT_BRACE,
	BLANK,
	IDENT,
	STRING,
	AND,
	OR,
	PIPE,
	EOF,
}					t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*text;
}					t_token;

t_token				*token_new(t_token_type type, char *text);
t_token				*token_free(t_token *token);

#endif
