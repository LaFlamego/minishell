/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_scan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 15:24:33 by Oery              #+#    #+#             */
/*   Updated: 2026/04/09 17:03:04 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../scanner.h"

static t_token	*scan_grouping(t_scanner *s, char c)
{
	if (c == '(')
		return (scanner_add_token(s, LEFT_PAREN));
	else if (c == ')')
		return (scanner_add_token(s, RIGHT_PAREN));
	else if (c == '{')
		return (scanner_add_token(s, LEFT_BRACE));
	else if (c == '}')
		return (scanner_add_token(s, RIGHT_BRACE));
	return (NULL);
}

static t_token	*scan_redirection(t_scanner *s, char c)
{
	if (c == '<')
	{
		if (scanner_match(s, '<'))
			return (scanner_add_token(s, REDIRECT_IN_UNTIL));
		else
			return (scanner_add_token(s, REDIRECT_IN));
	}
	else if (c == '>')
	{
		if (scanner_match(s, '>'))
			return (scanner_add_token(s, REDIRECT_OUT_APPEND));
		else
			return (scanner_add_token(s, REDIRECT_OUT));
	}
	return (NULL);
}

// TODO: Handle DQ Strings
// > End with operator or "

// TODO: Maybe group with kinds, like grouping / binary ops / unary
// > Would a dollar sign be an unary?
t_token	*token_scan(t_scanner *s)
{
	char	c;

	c = scanner_advance(s);
	if (c == '(' || c == ')' || c == '{' || c == '}')
		return (scan_grouping(s, c));
	else if (c == '$')
		return (scanner_add_token(s, DOLLAR));
	else if (c == '*')
		return (scanner_add_token(s, STAR));
	else if (c == '&')
	{
		if (scanner_match(s, '&'))
			return (scanner_add_token(s, AND));
		else
		{
			// TODO: should it be printable then?
			return (NULL);
		}
	}
	else if (c == '|')
	{
		if (scanner_match(s, '|'))
			return (scanner_add_token(s, OR));
		else
			return (scanner_add_token(s, PIPE));
	}
	else if (c == '<' || c == '>')
		return (scan_redirection(s, c));
	else if (c == '\'')
		return (token_scan_string(s));
	else if (ft_isspace(c))
		return (token_scan_blank(s));
	else if (is_valid_ident(c))
		return (token_scan_ident(s));
	return (NULL);
}
