/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_filter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 00:54:31 by Oery              #+#    #+#             */
/*   Updated: 2026/05/17 00:54:39 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

static void	handle_wildcard(char **star, char **match, char **filter,
		char **file)
{
	*star = *filter;
	*match = *file;
	*filter += 1;
}

static void	handle_char_match(char **file, char **filter)
{
	*file += 1;
	*filter += 1;
}

static void	handle_previous_star(char **file, char **filter, char **star,
		char **match)
{
	*filter = *star + 1;
	*match += 1;
	*file = *match;
}

static bool	handle_char(char **file, char **filter, char **star, char **match)
{
	if (*filter && **filter == **file)
		handle_char_match(file, filter);
	else if (**filter == '*')
		handle_wildcard(star, match, filter, file);
	else if (*star)
		handle_previous_star(file, filter, star, match);
	else
		return (false);
	return (true);
}

bool	is_filtered(char *file, char *filter)
{
	char	*star;
	char	*match;

	star = 0;
	match = 0;
	if (!file)
		return (false);
	if (!filter)
		return (true);
	while (*file)
	{
		if (!handle_char(&file, &filter, &star, &match))
			return (false);
	}
	while (*filter == '*')
		filter++;
	return (*filter == '\0');
}
