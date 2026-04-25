/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:11:10 by Oery              #+#    #+#             */
/*   Updated: 2026/04/17 17:18:34 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/env/env.h"
#include "src/scanner/token/token.h"

static size_t	get_value_length(char *key, t_env *env)
{
	char	*value;

	value = env_get(env, key);
	if (!value)
		return (0);
	return (ft_strlen(value));
}

// dollar signs can escape each other
// a dollar sign before EOF become regular text
static size_t	get_var_size(t_array *tokens, size_t i, t_env *env)
{
	t_token	*t;

	if (i + 1 >= tokens->size)
		return (1);
	t = tokens->data[i + 1];
	if (t->type == DOLLAR)
		return (1);
	return (get_value_length(t->text, env));
}

size_t	get_arg_expanded_size(t_array *tokens, t_env *env)
{
	t_token	*t;
	size_t	total;
	size_t	i;

	total = 0;
	i = 0;
	while (i < tokens->size)
	{
		t = tokens->data[i];
		if (t->type == STRING)
			total += ft_strlen(t->text);
		if (t->type == DOLLAR)
		{
			total += get_var_size(tokens, i, env);
			i++;
		}
		i++;
	}
	return (total + 1);
}
