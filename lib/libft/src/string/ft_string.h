/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 00:53:09 by Oery              #+#    #+#             */
/*   Updated: 2026/03/13 00:55:46 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stdlib.h>

typedef struct s_string
{
	char	*content;
	size_t	length;
	size_t	capacity;
}			t_string;

char		*ft_string_alloc(t_string *s, size_t size);
char		*ft_string_realloc(t_string *s, size_t new_size);
char		*ft_string_free(t_string *s);
t_string	ft_string_from_cstring(char *str);

#endif
