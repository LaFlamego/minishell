/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 17:12:09 by Oery              #+#    #+#             */
/*   Updated: 2026/03/22 17:12:57 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUT_H
# define FT_PUT_H

int		ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putstr_fd_max(char *s, int fd, int max);

#endif
