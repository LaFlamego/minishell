/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 13:32:36 by Oery              #+#    #+#             */
/*   Updated: 2026/03/13 23:01:46 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft/array.h"
#include "libft/printf.h"
#include "libft/string.h"
#include <stdlib.h>

// FIXME: All push operations can fail and should be handled
// FIXME: We're losing quote kind

// TODO: Add all operators
static bool	is_special(const char c)
{
	if (c == '\'' || c == '\"')
		return (true);
	if (c == '>' || c == '<')
		return (true);
	if (c == '$')
		return (true);
	return (false);
}

// TODO: Return an error if the string is not full
t_string	*ms_dq_string(const char *s, size_t *i)
{
	t_string	*word;

	(*i)++;
	word = malloc(sizeof(t_string));
	if (!word)
		return (NULL);
	ft_string_alloc(word, 0);
	while (s[*i] && s[*i] != '"')
	{
		ft_string_push(word, s[*i]);
		(*i)++;
	}
	// if s[*i] == '/0', return a syntax error
	ft_string_push(word, '\0');
	(*i)++;
	return (word);
}

// TODO: Return an error if the string is not full
t_string	*ms_sq_string(const char *s, size_t *i)
{
	t_string	*word;

	(*i)++;
	word = malloc(sizeof(t_string));
	if (!word)
		return (NULL);
	ft_string_alloc(word, 0);
	while (s[*i] && s[*i] != '\'')
	{
		ft_string_push(word, s[*i]);
		(*i)++;
	}
	// if s[*i] == '/0', return a syntax error
	ft_string_push(word, '\0');
	(*i)++;
	return (word);
}

t_string	*ms_word(const char *s, size_t *i)
{
	t_string	*word;

	word = malloc(sizeof(t_string));
	if (!word)
		return (NULL);
	ft_string_alloc(word, 0);
	while (s[*i] && !ft_isspace(s[*i]) && !is_special(s[*i]))
	{
		ft_string_push(word, s[*i]);
		(*i)++;
	}
	ft_string_push(word, '\0');
	return (word);
}

void	skip_whitespace(const char *s, size_t *i)
{
	while (s[*i] && ft_isspace(s[*i]))
		(*i)++;
}

t_string	*cmd_parse_word(const char *s, size_t *i)
{
	if (s[*i] == '\'')
		return (ms_sq_string(s, i));
	if (s[*i] == '"')
		return (ms_dq_string(s, i));
	if (s[*i] == '$')
		return (ms_word(s, i));
	return (ms_word(s, i));
}

t_array	*cmd_parse(const char *s)
{
	size_t		i;
	t_array		*words;
	t_string	*word;

	words = ft_array_alloc();
	i = 0;
	skip_whitespace(s, &i);
	while (s && s[i])
	{
		word = cmd_parse_word(s, &i);
		if (!word)
			return (NULL);
		ft_array_push(words, word);
		skip_whitespace(s, &i);
	}
	i = 0;
	while (i < words->size)
	{
		ft_printf("%s\n", ((t_string *)words->data[i])->content);
		i++;
	}
	return (words);
}
