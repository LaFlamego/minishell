/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_target.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 19:07:18 by Oery              #+#    #+#             */
/*   Updated: 2026/05/06 19:12:07 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./expand.h"
#include <stdlib.h>

// TODO: Handle incorrect part kinds
static int	expand_part(t_word_part *part, t_string *arg, t_env *env)
{
	if (part->kind == WK_STRING && !ft_string_push_str(arg, part->data))
		return (0);
	if (part->kind == WK_VARIABLE && !expand_variable(arg, part->data, env))
		return (0);
	return (1);
}

char	*expand_target(t_word *parts, t_env *env)
{
	t_string	*arg;
	t_word		*curr;
	char		*result;

	arg = ft_string_new(0);
	curr = parts;
	if (!arg)
		return (0);
	while (curr)
	{
		if (!expand_part(curr->content, arg, env))
		{
			ft_string_free(arg);
			return (0);
		};
		curr = curr->next;
	}
	result = arg->content;
	free(arg);
	return (result);
}
