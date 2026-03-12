/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:31:59 by Oery              #+#    #+#             */
/*   Updated: 2026/03/12 18:23:00 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAY_H
# define FT_ARRAY_H

# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>

typedef struct s_array
{
	void	**data;
	size_t	size;
	size_t	capacity;
}			t_array;

// > ft_array.c
t_array		*ft_array_alloc(void);
void		ft_array_free(t_array *arr, void (*f)(void *));
void		ft_array_pop(t_array *arr, void **ptr);
size_t		ft_array_push(t_array *arr, void *ptr);

// > ft_array.iter.c
void		ft_array_foreach(t_array *arr, void (*f)(void *));
void		*ft_array_find(t_array *arr, bool (*f)(void *));

#endif
