/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crevette <coincoin@baozi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:00:56 by Oery              #+#    #+#             */
/*   Updated: 2026/03/13 00:56:47 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "src/array/ft_array.h"
# include "src/string/ft_string.h"
# include <stdarg.h>
# include <stdlib.h>

// >> Char
int						ft_isalnum(int c);
int						ft_isalpha(int c);
int						ft_isascii(int c);
int						ft_isdigit(int c);
int						ft_isprint(int c);
int						ft_isspace(int c);
int						ft_tolower(int c);
int						ft_toupper(int c);

// >> GNL
char					*get_next_line(int fd);

typedef struct s_gnl_list
{
	int					fd;
	char				*buf;
	struct s_gnl_list	*next;
}						t_gnl_list;

// >> Linked Lists
typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}						t_list;

void					ft_lstadd_back(t_list **lst, t_list *new);
void					ft_lstadd_front(t_list **lst, t_list *new);
void					ft_lstclear(t_list **lst, void (*del)(void *));
void					ft_lstdelone(t_list *lst, void (*del)(void *));
void					ft_lstiter(t_list *lst, void (*f)(void *));
t_list					*ft_lstlast(t_list *lst);
t_list					*ft_lstmap(t_list *lst, void *(*f)(void *),
							void (*del)(void *));
t_list					*ft_lstnew(void *content);
t_list					*ft_lstpop_back(t_list **lst);
t_list					*ft_lstpop_front(t_list **lst);
int						ft_lstsize(t_list *lst);

// >> Maths
int						ft_abs(int a);
int						ft_max(int a, int b);
int						ft_min(int a, int b);

// >> Memory
void					*ft_bzero(void *s, size_t n);
void					*ft_calloc(size_t n, size_t size);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					*ft_memmove(void *dest, const void *src, size_t n);
void					*ft_memset(void *s, int c, size_t n);
char					*ft_strdup(const char *s);
char					*ft_strldup(const char *s, int n);

// >> Printf
# define STYLE_ALTERNATE 1
# define STYLE_EXPLICIT_SIGN 2
# define STYLE_SPACE_SIGN 4
# define STYLE_JUSTIFY_LEFT 8
# define STYLE_PAD_ZERO 16
# define STYLE_PAD_BLANK 32

typedef struct s_flags
{
	int					min_width;
	int					precision;
	int					style;
}						t_flags;

t_flags					*new_flags(void);
int						ft_dprintf(int fd, const char *fmt, ...);
int						ft_printf(const char *fmt, ...);
int						ft_printf_put(const char **fmt, int fd);
int						ft_printf_pct(int fd);
int						ft_printf_str(va_list *ap, t_flags *flags, int fd);
int						ft_printf_ptr(va_list *ap, t_flags *flags, int fd);
int						ft_printf_nbr(va_list *ap, t_flags *flags, int fd);
int						ft_printf_nbr_u(va_list *ap, t_flags *flags, int fd);
int						ft_printf_nbr_base(long nbr, char *base, t_flags *flags,
							int fd);
int						ft_printf_nbr_u_base(unsigned long nbr, char *base,
							int fd);
int						ft_printf_hex_l(va_list *ap, t_flags *flags, int fd);
int						ft_printf_hex_u(va_list *ap, t_flags *flags, int fd);
int						ft_printf_char(va_list *ap, t_flags *flags, int fd);
int						ft_pad(t_flags *flags, int length, int fd);
int						ft_pad_precision(t_flags *flags, int len, int fd);
int						ft_length_nbr_base(long nbr, char *base,
							t_flags *flags);
int						ft_length_nbr_u_base(unsigned long nbr, char *base);
int						is_flag(char c);
int						is_spec(char c);
void					set_flag(const char **fmt, t_flags *flags);
int						handle_spec(const char **fmt, t_flags *flags,
							va_list *ap, int fd);
int						ft_read_int(const char **fmt);
void					ft_panic(int status, const char *fmt, ...);

// >> Put
int						ft_putchar_fd(char c, int fd);
void					ft_putendl_fd(char *s, int fd);
void					ft_putnbr_fd(int n, int fd);
int						ft_putstr_fd(char *s, int fd);
int						ft_putstr_fd_max(char *s, int fd, int max);

// >> Strings

int						ft_atoi(const char *str);
char					*ft_basename(const char *path);
char					*ft_itoa(int n);
char					**ft_split(char const *s, char c);
void					*free_splits(char **splits);
char					*ft_strrchr(const char *s, char c);
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strjoin(char const *s1, char const *s2);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
size_t					ft_strlcpy(char *dst, const char *src, size_t size);
size_t					ft_strlen(const char *s);
char					*ft_strmapi(char const *s, char (*f)(unsigned int,
								char));
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_streq(const char *s1, const char *s2);
char					*ft_strnstr(const char *big, const char *little,
							size_t len);
char					*ft_strchr(const char *s, int c);
char					*ft_strtrim(char const *s1, char const *set);
char					*ft_substr(const char *s, unsigned int start,
							size_t len);
int						ft_endswith(const char *string, const char *suffix);
int						ft_startswith(const char *string, const char *prefix);

#endif
