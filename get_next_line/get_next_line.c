/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:10:32 by mtripodi          #+#    #+#             */
/*   Updated: 2024/04/24 16:55:17 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 ** Function name: get_next_line
 ** -----------------------------
 ** Prototype: char *get_next_line(int fd);
 **
 ** Parameters:
 **    fd: The file descriptor to read from.
 **
 ** Return value:
 **    Read line: correct behavior
 **    NULL: there is nothing else to read, or an error occurred.
 **
 ** External functions: read, malloc, free
 **
 ** Description:
 **    Write a function that returns a line read from a file descriptor.
 */

/*
 ** ssize_t read(int fildes, void *buf, size_t nbyte);
 **
 ** DESCRIPTION
 **     read() attempts to read nbyte bytes of data from the object referenced
 **     by the descriptor fildes into the buffer pointed to by buf.
 */

#include "get_next_line.h"

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	i;

	i = 0;
	if (!s || start >= ft_strlen(s))
		return (NULL);
	if ((ft_strlen(s) - start) < len)
		len = ft_strlen(s) - start;
	out = malloc(len + 1);
	if (out == NULL)
		return (NULL);
	while (*s && i < len && start < ft_strlen(s))
	{
		out[i] = s[i + start];
		i++;
	}
	out[i] = '\0';
	return (out);
}

static char	*newline(t_list **lst)
{
	size_t	nl;
	char	*str;
	char	*strhead;
	char	*line;

	line = NULL;
	str = ft_substr((*lst)->buffer, 0, ft_strlen((*lst)->buffer));
	strhead = str;
	ft_lstdelone(lst, free);
	nl = 0;
	while (str[nl] != '\0' && str[nl] != '\n')
		nl++;
	if (!line)
		line = ft_substr(str, 0, nl + 1);
	if (nl > 0 && nl == ft_strlen(str))
		nl--;
	str += nl + 1;
	if(*str)
		*lst = string_into_linkedlist(lst, (ft_substr(str, 0, ft_strlen(str))));
	free(strhead);
	strhead = NULL;
	return (line);
}

static void	update_list(t_list **lst, char *buffer)
{
	char	*new_buffer;

	if (!*buffer)
		return ;

	if (!*lst)
	{
		*lst = string_into_linkedlist(lst, ft_substr(buffer, 0, ft_strlen(buffer)));
		return ;
	}
	new_buffer = ft_strjoin((*lst)->buffer, (char *)buffer);
	ft_lstdelone(&(*lst), free);
	*lst = string_into_linkedlist(lst, ft_substr(new_buffer, 0, ft_strlen(new_buffer)));
	free(new_buffer);
	new_buffer = NULL;
}

static t_list	*read_to_node(int fd, t_list **lst) 
{
	ssize_t		bytes_read;
	char		*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		if (bytes_read == 0)
			break ;
		update_list(lst, buffer);
		if (ischar((*lst)->buffer, '\n') == 1)
			break ;
	}
	free(buffer);
	return (*lst);
}

char	*get_next_line(int fd)
{
	static t_list		*lst;
	char			*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	lst = read_to_node(fd, &lst);
	if (!lst)
		return (NULL);
	if (lst)
		line = newline(&lst);
	if (line != NULL)
		return (line);
	return (NULL);
}
