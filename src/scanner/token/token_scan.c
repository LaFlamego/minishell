/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_scan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 15:24:33 by Oery              #+#    #+#             */
/*   Updated: 2026/05/05 12:28:54 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../scanner.h"

static t_token	*scan_grouping(t_scanner *s)
{
	if (scanner_match(s, '('))
		return (scanner_add_token(s, LEFT_PAREN));
	else if (scanner_match(s, ')'))
		return (scanner_add_token(s, RIGHT_PAREN));
	return (NULL);
}

static t_token	*scan_redirection(t_scanner *s)
{
	if (scanner_match(s, '<'))
	{
		if (scanner_match(s, '<'))
			return (scanner_add_token(s, REDIRECT_IN_UNTIL));
		else
			return (scanner_add_token(s, REDIRECT_IN));
	}
	else if (scanner_match(s, '>'))
	{
		if (scanner_match(s, '>'))
			return (scanner_add_token(s, REDIRECT_OUT_APPEND));
		else
			return (scanner_add_token(s, REDIRECT_OUT));
	}
	return (NULL);
}

static t_token	*scan_binary(t_scanner *s)
{
	if (scanner_match(s, '&') && scanner_match(s, '&'))
	{
		return (scanner_add_token(s, AND));
	}
	else if (scanner_match(s, '|'))
	{
		if (scanner_match(s, '|'))
			return (scanner_add_token(s, OR));
		else
			return (scanner_add_token(s, PIPE));
	}
	return (NULL);
}

// TODO: Should we support ${VARIABLE} ?

t_token	*token_scan(t_scanner *s)
{
	char	c;

	c = scanner_peek(s);
	if (c == '(' || c == ')')
		return (scan_grouping(s));
	else if (scanner_match(s, '$'))
		return (scanner_add_token(s, DOLLAR));
	else if (scanner_match(s, '*'))
		return (scanner_add_token(s, STAR));
	else if ((c == '&' && scanner_peek_next(s) == '&') || c == '|')
		return (scan_binary(s));
	else if (c == '<' || c == '>')
		return (scan_redirection(s));
	else if (scanner_match(s, '\''))
		return (token_scan_string(s));
	else if (scanner_match(s, '"'))
		return (token_scan_string_double(s));
	else if (ft_isspace(c))
		return (token_scan_blank(s));
	else
		return (token_scan_ident(s));
}
