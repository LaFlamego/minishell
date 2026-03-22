/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oery <coincoin@baozi>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 18:42:10 by Oery              #+#    #+#             */
/*   Updated: 2026/03/22 18:54:39 by Oery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STR_H
# define FT_STR_H

# include "../array/ft_array.h"

t_array	*ft_split_space(const char *s);
int		ft_atoi(const char *str);
char	*ft_basename(const char *path);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
void	*free_splits(char **splits);
char	*ft_strrchr(const char *s, char c);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_streq(const char *s1, const char *s2);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(const char *s, unsigned int start, size_t len);
int		ft_endswith(const char *string, const char *suffix);
int		ft_startswith(const char *string, const char *prefix);

#endif
