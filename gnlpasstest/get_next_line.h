/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:33:01 by pvaladar          #+#    #+#             */
/*   Updated: 2024/07/25 12:57:26 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h> // used by read(), STDOUT_FILENO, STDERR_FILENO
# include <stdlib.h> // definition of size_t and NULL (e.g.: ft_memset)

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// Functions in my get_next_line.c
// ---  ------------------------- ------
char	*ft_before(const char *str);
char	*ft_after(char *str);
int		ft_newline(const char *str);
char	*ft_read(int fd, char *buffer, char *tmp, char *str);
char	*get_next_line(int fd);

// Functions in my get_next_line_utils.c
// ---  ------------------------- ------
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	null_free(char **str);

#endif
