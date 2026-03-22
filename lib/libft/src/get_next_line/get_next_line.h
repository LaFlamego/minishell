/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 17:57:33 by Oery              #+#    #+#             */
/*   Updated: 2026/03/22 17:58:23 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 42

# endif

char					*get_next_line(int fd);

typedef struct s_gnl_list
{
	int					fd;
	char				*buf;
	struct s_gnl_list	*next;
}						t_gnl_list;

#endif
