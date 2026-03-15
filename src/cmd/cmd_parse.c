/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 13:32:36 by Oery              #+#    #+#             */
/*   Updated: 2026/03/15 00:54:58 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft/array.h"
#include "libft/printf.h"
#include "libft/string.h"
#include "minishell/env.h"
#include <stddef.h>
#include <stdlib.h>

// FIXME: All push operations can fail and should be handled
// FIXME: We're losing quote kind

// TODO: Add all operators
static bool	is_special(const char c)
{
	if (c == '\'' || c == '\"')
		return (true);
	// if (c == '>' || c == '<')
	// 	return (true);
	// if (c == '$')
	// 	return (true);
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
	// i = 0;
	// while (i < words->size)
	// {
	// 	ft_printf("%s\n", ((t_string *)words->data[i])->content);
	// 	i++;
	// }
	return (words);
}

// FIXME: Single $ should stay a single dollar sign
// Maybe handle substitutions as separated Nodes ?
// Then each node would have an array of subnodes.
// Would process to a final node
void	cmd_word_expand(t_env *env, t_array *words, size_t i)
{
	char		*val;
	t_string	*word;

	word = words->data[i];
	if (!word->content)
		return ;
	if (word->content[0] == '$')
	{
		val = ft_env_get(env, word->content + 1);
		free(word->content);
		word->content = ft_strdup(val);
		word->size = ft_strlen(val) + 1;
		word->capacity = word->size;
	}
	// var = ft_strchr(word->content, '$');
	// while (var)
	// {
	// 	// TODO: Replace var with its value
	// 	// Get Key
	// 	// Look up key
	// 	// Replace Key with Val
	// 	var = ft_strchr(word->content, '$');
	// }
}

// TODO: Expand substitutions
// > does nested substitutions exist or are they done at the same time?
t_array	*cmd_expand(t_env *env, t_array *words)
{
	size_t		i;
	t_string	*word;

	i = 0;
	while (i < words->size)
	{
		cmd_word_expand(env, words, i);
		i++;
	}
	i = 0;
	while (i < words->size)
	{
		word = words->data[i];
		ft_printf("%s ", word->content);
		i++;
	}
	ft_printf("\n");
	return (NULL);
}

// FIRST LAYER:
//
//	Split Command into words
//	> You cannot just split spaces
//	>> "    "
//	Expand every word
// IF node was expanded > parse it's output
