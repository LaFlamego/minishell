/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 17:41:16 by Oery              #+#    #+#             */
/*   Updated: 2026/03/22 18:52:13 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include "../array/ft_array.h"
# include <stddef.h>

typedef struct s_string
{
	char	*content;
	size_t	size;
	size_t	capacity;
}			t_string;

t_string	ft_string_init(void);
t_string	*ft_string_new(size_t capacity);
char		*ft_string_realloc(t_string *s, size_t new_size);
void		*ft_string_resize(t_string *s, size_t size);
void		ft_string_free(void *raw_t_string);
size_t		ft_string_push(t_string *s, char c);
size_t		ft_string_push_str(t_string *s, const char *str);
size_t		ft_string_push_string(t_string *dst, const t_string *src);
t_string	ft_string_from_cstring(char *str);
t_string	ft_string_from_cstring_alloc(char *str);
t_string	*ft_string_join(const t_array *parts);

#endif
