/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 22:47:36 by Oery              #+#    #+#             */
/*   Updated: 2026/05/17 18:02:46 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

static char	*skip_symbols(char *s)
{
	while (s && *s)
	{
		if (ft_isalnum(*s))
			return (s);
		s++;
	}
	return (NULL);
}

static int	ft_strcmplw(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && ft_tolower(s1[i]) == ft_tolower(s2[i]))
		i++;
	return ((unsigned char)(ft_tolower(s1[i]))
		- (unsigned char)(ft_tolower(s2[i])));
}

static int	sort_fn(void *a, void *b)
{
	t_string	*sa;
	t_string	*sb;
	char		*sas;
	char		*sbs;

	if (!a)
		return (1);
	if (!b)
		return (-1);
	sa = a;
	sb = b;
	sas = skip_symbols(sa->content);
	sbs = skip_symbols(sb->content);
	if (!sas || !sbs)
		return (ft_strcmplw(sa->content, sb->content));
	return (ft_strcmplw(sas, sbs));
}

void	files_sort(t_array *files)
{
	ft_array_sort(files, &sort_fn);
}
