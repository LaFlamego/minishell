/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 14:09:13 by Oery              #+#    #+#             */
/*   Updated: 2026/04/16 14:33:04 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"
#include "libft.h"

// TODO: Should it be printed to stderr?
void	*parser_error(t_token *t)
{
	ft_dprintf(2, "minishell: syntax error near unexpected token `%s'\n",
		token_to_string(t));
	return (NULL);
}
