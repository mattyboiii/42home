/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:54:30 by mtripodi          #+#    #+#             */
/*   Updated: 2024/07/25 16:35:22 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h> //malloc, free
# include <unistd.h> //read

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

// Functions in my get_next_line_utils.c
// ---  ------------------------- ------
int		ischar(char *str, int start, char c);
int		ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	null_free(char **ptr);

#endif
