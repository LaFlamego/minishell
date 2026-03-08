/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_interative_mode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 16:41:21 by crevette          #+#    #+#             */
/*   Updated: 2026/03/08 16:52:18 by crevette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>

int	is_interactive_mode(void)
{
	return (isatty(STDIN_FILENO));
}
