/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:39:11 by Oery              #+#    #+#             */
/*   Updated: 2026/04/15 18:01:52 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "src/scanner/token/token.h"
#include <stdlib.h>

// WARN: Watch out for errors

void	expand_word(t_array *cmd, t_array *tokens)
{
	size_t	i;
	t_token	*t;

	i = 0;
	while (i < tokens->size)
	{
		t = tokens->data[i];
		if (t->type == DOLLAR)
		{
			// ident is at index i + 1
		}
		if (t->type == STRING)
		{
			// ft_strdup()
		}
		i++;
	}
	// TODO: Token is either a DOLLAR or a STRING
	// DOLLAR must be followed by STRING
}

void	expand_words(t_array *cmd, t_array *words)
{
	size_t	i;

	i = 0;
	while (i < words->size)
	{
		// TODO: handle error
		expand_word(cmd, words->data[i]);
		i++;
	}
}

// TODO: Turn a stream of token into argvs
char	**expand_cmd(t_array *words)
{
	t_array	*cmd;
	char	**ret;

	cmd = ft_array_new();
	if (!cmd)
		return (NULL);
	expand_words(cmd, word);
	ret = (char **)cmd->data;
	free(cmd);
	ft_strjoin(cmd->data, '0');
	return (ret);
}
