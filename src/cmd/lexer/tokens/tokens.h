/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 19:19:31 by Oery              #+#    #+#             */
/*   Updated: 2026/04/02 01:20:31 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENS_H
# define TOKENS_H

# include "src/cmd/lexer/lexer.h"

int	tokens_char(t_lexer *l, t_token *token, t_token_kind kind);
int	tokens_blank(t_lexer *l, t_token *token);
int	tokens_ident(t_lexer *l, t_token *token);
int	tokens_sq_string(t_lexer *l, t_token *token);

#endif
