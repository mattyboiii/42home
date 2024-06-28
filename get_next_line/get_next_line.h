/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:11:33 by mtripodi          #+#    #+#             */
/*   Updated: 2024/06/28 12:24:27 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h> //malloc, freee
# include <unistd.h> //read
# include <limits.h> //OPEN_MAX
//Definitions
/*
 * Because im checking buffer size on first call of the function, I decided
 * to make the default buffer size 42. Setting the buffer size here is will
 * make it the defualt buffer size if the user does not set one. 
 */

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	char			*buffer;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);

// Functions in my get_next_line_utils.c
// ---  ------------------------- ------
int		ischar(char *str, int start, char c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	null_free(char **ptr);

#endif
