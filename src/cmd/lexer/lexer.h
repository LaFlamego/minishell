/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:56:34 by Oery              #+#    #+#             */
/*   Updated: 2026/04/01 18:26:50 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "libft.h"
# include <stddef.h>

typedef enum e_token_kind
{
	BLANK,
	LIT_STR,
	DOLLAR,
	PAR_OPEN,
	PAR_CLOSE,
	IDENT,
	PIPE,
	AND,
	OR,
}					t_token_kind;

typedef struct s_token
{
	t_token_kind	kind;
	char			*data;
}					t_token;

typedef struct s_lexer
{
	const char		*input;
	size_t			idx;
	t_token			*next_token;
}					t_lexer;

t_lexer				lexer_new(const char *input);
int					lexer_advance(t_lexer *lex);

#endif
