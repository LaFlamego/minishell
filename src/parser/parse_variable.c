/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_variable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 20:02:51 by Oery              #+#    #+#             */
/*   Updated: 2026/05/05 12:25:55 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"
#include "src/cmd/tree/word/word.h"

static bool	is_reserved(char c)
{
	if (c == '?')
		return (true);
	return (false);
}

static bool	is_forbidden_char(char c)
{
	return (c != '_' && !ft_isdigit(c) && !ft_isalpha(c));
}

// FIXME:
// Variables cannot start with a number but redirections target can
// i think we simply don't care? it should fix itself

static bool	is_valid_ident(const char *ident)
{
	size_t	i;

	i = 0;
	if (ft_strlen(ident) == 1 && is_reserved(ident[0]))
		return (true);
	while (ident && ident[i])
	{
		if (i == 0 && ft_isdigit(ident[i]))
			return (false);
		if (is_forbidden_char(ident[i]))
			return (false);
		i++;
	}
	return (i != 0);
}

/**
 * parser_parse_variable() - parse a variable
 * @p: instance of a `t_parser`
 *
 * User defined variables start with a letter or an underscore.
 * They can be followed by digits.
 * Shell variables can start with reserved symbols.
 *
 * Return:
 * A Variable node if the value is a valid identifier.
 * A String node if the value is not a valid identifier.
 * NULL on failure.
 */
t_word_part	*parser_parse_variable(t_parser *p)
{
	t_token	*string;

	if (parser_check(p, BLANK))
	{
		return (part_new(WK_STRING, "$"));
	}
	else if (parser_match(p, DOLLAR))
	{
		return (part_new(WK_VARIABLE, "$"));
	}
	else if (parser_check(p, STRING))
	{
		string = parser_peek(p);
		if (!is_valid_ident(string->text) && !ft_streq(string->text, "$"))
		{
			return (part_new(WK_STRING, "$"));
		}
		parser_advance(p);
		return (part_new(WK_VARIABLE, string->text));
	}
	else
	{
		return (part_new(WK_STRING, "$"));
	}
}
