/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 00:53:09 by Oery              #+#    #+#             */
/*   Updated: 2026/03/13 18:17:15 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include <stddef.h>

typedef struct s_string
{
	char	*content;
	size_t	size;
	size_t	capacity;
}			t_string;

char		*ft_string_alloc(t_string *s, size_t size);
char		*ft_string_realloc(t_string *s, size_t new_size);
char		*ft_string_free(t_string *s);
void		*ft_string_resize(t_string *s, size_t size);
size_t		ft_string_push(t_string *s, char c);
t_string	ft_string_from_cstring(char *str);

#endif
