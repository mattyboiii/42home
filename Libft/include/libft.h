/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:01:31 by mtripodi          #+#    #+#             */
/*   Updated: 2024/03/06 14:32:37 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#	define LIBFT_H

#	include <stdio.h>
#	include <unistd.h>
#	include <ctype.h>
#	include <stddef.h>
#	include <stdlib.h>
#	include <string.h>

int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcat(char *dest, const char *src, size_t destsize);

void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);



#endif

