/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 18:06:57 by Oery              #+#    #+#             */
/*   Updated: 2026/03/13 18:07:36 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>

# define STYLE_ALTERNATE 1
# define STYLE_EXPLICIT_SIGN 2
# define STYLE_SPACE_SIGN 4
# define STYLE_JUSTIFY_LEFT 8
# define STYLE_PAD_ZERO 16
# define STYLE_PAD_BLANK 32

typedef struct s_flags
{
	int	min_width;
	int	precision;
	int	style;
}		t_flags;

t_flags	*new_flags(void);
int		ft_dprintf(int fd, const char *fmt, ...);
int		ft_printf(const char *fmt, ...);
int		ft_printf_put(const char **fmt, int fd);
int		ft_printf_pct(int fd);
int		ft_printf_str(va_list *ap, t_flags *flags, int fd);
int		ft_printf_ptr(va_list *ap, t_flags *flags, int fd);
int		ft_printf_nbr(va_list *ap, t_flags *flags, int fd);
int		ft_printf_nbr_u(va_list *ap, t_flags *flags, int fd);
int		ft_printf_nbr_base(long nbr, char *base, t_flags *flags, int fd);
int		ft_printf_nbr_u_base(unsigned long nbr, char *base, int fd);
int		ft_printf_hex_l(va_list *ap, t_flags *flags, int fd);
int		ft_printf_hex_u(va_list *ap, t_flags *flags, int fd);
int		ft_printf_char(va_list *ap, t_flags *flags, int fd);
int		ft_pad(t_flags *flags, int length, int fd);
int		ft_pad_precision(t_flags *flags, int len, int fd);
int		ft_length_nbr_base(long nbr, char *base, t_flags *flags);
int		ft_length_nbr_u_base(unsigned long nbr, char *base);
int		is_flag(char c);
int		is_spec(char c);
void	set_flag(const char **fmt, t_flags *flags);
int		handle_spec(const char **fmt, t_flags *flags, va_list *ap, int fd);
int		ft_read_int(const char **fmt);
void	ft_panic(int status, const char *fmt, ...);

#endif
