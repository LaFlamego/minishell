/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 21:51:19 by Oery              #+#    #+#             */
/*   Updated: 2026/04/28 22:57:46 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <unistd.h>

int			g_sigint_received = 0;

static int	error(void)
{
	ft_dprintf(2, "error: failed to set signal handler\n");
	return (0);
}

/** handle_signal() - handle incoming signals
 * @signal: signal to handle
 *
 * On SIGINT, kill the running command
 * On SIGQUIT, do nothing. (cancels signal sent by CTRL+\)
 */
static void	handle_signal(int signal)
{
	if (signal == SIGINT)
		g_sigint_received = 0;
	if (signal == SIGQUIT)
		return ;
}

int	set_signal_action(void)
{
	struct sigaction	action;

	action.sa_flags = 0;
	action.sa_handler = &handle_signal;
	sigemptyset(&action.sa_mask);
	if (sigaction(SIGINT, &action, NULL) == -1)
		return (error());
	if (sigaction(SIGQUIT, &action, NULL) == -1)
		return (error());
	return (1);
}

int	setup_signals_handlers(void)
{
	if (!set_signal_action())
		return (0);
	return (1);
}
