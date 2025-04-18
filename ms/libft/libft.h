/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:01:31 by mtripodi          #+#    #+#             */
/*   Updated: 2024/09/25 17:18:53 by matthew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <unistd.h> //read
# include <limits.h>
# include <ctype.h>
# include <stddef.h>
# include <stdlib.h> //malloc, free
# include <string.h>
# include <stdarg.h> // va_start, va_arg, va_end, va_copy

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
long	ft_atoi(const char *str);

size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dest, const char *src, size_t destsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

char	*ft_strdup(const char *src);
char	*ft_strchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);

void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_calloc(size_t count, size_t size);

// part 2
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	**ft_split(char const *s, char c);

void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

// Personal small Functions
int		ft_strcmp(const char *s1, const char *s2);
int		ft_isnumber(char *s);
int		ft_isspace(int c);
int		ft_atoi_strict(const char *str, int *err);
void	null_free(char **ptr);
size_t	ischar(char *str, size_t start, char c);
char	*ft_strstr(const char *haystack, const char *needle);

// Double pointer array functions
int		dp_len(char **arr);
void	dp_free(char ***dp);
char	**dp_strcat(char **paths, char *str);

// Personal BIG Functions
char	*get_next_line(int fd);
int		ft_printf(const char *format, ...);

#endif
