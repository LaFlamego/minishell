/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 20:55:50 by Oery              #+#    #+#             */
/*   Updated: 2026/04/29 00:47:21 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "src/env/env.h"
#include "utils.h"
#include <fcntl.h>
#include <readline/history.h>
#include <stdlib.h>
#include <unistd.h>

// TODO: Should we only load last x entries?

/**
 * get_history_file() - get history file path
 * @env: environment variables
 *
 * Gets the history file location from $HISTFILE, or return
 * a default file location if the env variable is not valid.
 */
static char	*get_history_file(t_env *env)
{
	char	*file;

	file = env_get(env, "HISTFILE");
	if (!file || file[0] == '\0')
		return ("minishell_history.txt");
	return (file);
}

void	history_load(t_env *env)
{
	int		fd;
	char	*line;
	char	*stripped;

	fd = open(get_history_file(env), O_RDONLY);
	if (fd <= 0)
		return ;
	line = get_next_line(fd);
	while (line)
	{
		stripped = ft_strtrim(line, "\n");
		if (stripped)
		{
			add_history(stripped);
			free(stripped);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	history_save(t_env *env, const char *line)
{
	int	fd;

	if (!line || *line == '\0')
		return ;
	add_history(line);
	fd = open(get_history_file(env), O_WRONLY | O_CREAT | O_APPEND, S_IRWXU);
	if (fd <= 0)
		return ;
	write(fd, line, ft_strlen(line));
	write(fd, "\n", 1);
	close(fd);
}
