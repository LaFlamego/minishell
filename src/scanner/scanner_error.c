/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 00:18:43 by Oery              #+#    #+#             */
/*   Updated: 2026/05/18 23:30:21 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*scanner_error(char token)
{
	ft_dprintf(2, "minishell: syntax error near unexpected token `%c'\n",
		token);
	return (NULL);
}
