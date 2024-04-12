/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:11:33 by mtripodi          #+#    #+#             */
/*   Updated: 2024/04/09 10:49:56 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h> // this is so I can use STDOUT_FILENO, STDERR_FILENO
#include <limits.h> // so i can use OPEN_MAX which check max files allowed open
#include <stdlib.h> //malloc, freee
#include <string.h> //

//Definitions
/*
 * Because im checking buffer size on first call of the function, I decided
 * to make the default buffer size 42. Setting the buffer size here is will
 * make it the defualt buffer size if the user does not set one. 
 */

# ifndef BUFFER_SIZE
#	define BUFFER_SIZE 42
# endif

# define GNL_ERROR NULL
# define GNL_END_OF_FILE 0
# define GNL_NEWLINE 1

typedef struct s_list
{
	char	*buffer;
	struct	s_list *next;
}		t_list;

char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strcatmal(char *dest, const char *src, char *address);

char	*get_next_line(int fd);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
int	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);
void	delete_content(void *content);

#endif
