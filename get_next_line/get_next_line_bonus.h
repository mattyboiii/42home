/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:54:30 by mtripodi          #+#    #+#             */
/*   Updated: 2024/07/24 12:56:14 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h> //malloc, free
# include <unistd.h> //read

//Definitions
/*
 * Because im checking buffer size on first call of the function, I decided
 * to make the default buffer size 42. Setting the buffer size here is will
 * make it the defualt buffer size if the user does not set one. 
 */

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
