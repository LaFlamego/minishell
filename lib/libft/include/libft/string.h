/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 00:53:09 by Oery              #+#    #+#             */
/*   Updated: 2026/03/16 19:00:25 by Oery             ###   ########.fr       */
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

t_string	ft_string_init(void);
char		*ft_string_alloc(t_string *s, size_t size);
char		*ft_string_realloc(t_string *s, size_t new_size);
char		*ft_string_free(t_string *s);
void		*ft_string_resize(t_string *s, size_t size);
size_t		ft_string_push(t_string *s, char c);
size_t		ft_string_push_str(t_string *s, const char *str);
t_string	ft_string_from_cstring(char *str);
t_string	ft_string_from_cstring_alloc(char *str);

#endif
