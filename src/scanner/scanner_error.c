/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 00:18:43 by Oery              #+#    #+#             */
/*   Updated: 2026/04/09 16:50:26 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./scanner.h"

// TODO: Print error message with current i
// > Should it be printed to stderr?
void	*scanner_error(t_scanner *s, char token)
{
	char	found;

	ft_dprintf(2, "minishell: syntax error near unexpected token `%c'\n",
		token);
	return (NULL);
}
