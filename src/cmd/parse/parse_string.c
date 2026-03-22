/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 16:20:34 by Oery              #+#    #+#             */
/*   Updated: 2026/03/22 20:14:07 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell/parse.h"

static bool	is_string(const char c)
{
	if (c == '\'' || c == '\"')
		return (true);
	return (false);
}

// TODO: Return an error if the string is not full
static t_string	*ms_dq_string(const char *s, size_t *i)
{
	t_string	*word;

	word = ft_string_new(0);
	if (!word)
		return (NULL);
	ft_string_push(word, s[*i]);
	(*i)++;
	while (s[*i] && s[*i] != '"')
	{
		ft_string_push(word, s[*i]);
		(*i)++;
	}
	ft_string_push(word, s[*i]);
	// if s[*i] == '/0', return a syntax error
	(*i)++;
	return (word);
}

// TODO: Return an error if the string is not full
static t_string	*ms_sq_string(const char *s, size_t *i)
{
	t_string	*word;

	word = ft_string_new(0);
	if (!word)
		return (NULL);
	ft_string_push(word, s[*i]);
	(*i)++;
	while (s[*i] && s[*i] != '\'')
	{
		ft_string_push(word, s[*i]);
		(*i)++;
	}
	ft_string_push(word, s[*i]);
	// if s[*i] == '/0', return a syntax error
	(*i)++;
	return (word);
}

static t_string	*ms_word(const char *s, size_t *i)
{
	t_string	*word;

	word = ft_string_new(0);
	if (!word)
		return (NULL);
	while (s[*i] && !ft_isspace(s[*i]) && !is_string(s[*i]))
	{
		ft_string_push(word, s[*i]);
		(*i)++;
	}
	return (word);
}

t_string	*cmd_parse_string(const char *s, size_t *i)
{
	if (s[*i] == '\'')
		return (ms_sq_string(s, i));
	if (s[*i] == '"')
		return (ms_dq_string(s, i));
	if (s[*i] == '$')
		return (ms_word(s, i));
	return (ms_word(s, i));
}
