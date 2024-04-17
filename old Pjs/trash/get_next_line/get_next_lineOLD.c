/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:10:32 by mtripodi          #+#    #+#             */
/*   Updated: 2024/04/09 15:16:47 by mtripodi         ###   ########.fr       */
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

// if ((*lst)->buffer[ft_strlen((*lst)->buffer) - 1] == '\n')

char	*ft_substr(char const *s, unsigned int start, size_t len)
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

void	string_into_linkedlist(t_list **lst, char *str)
{
	t_list		*node;
	char		*temp;

	if (!str)
		return ;
	temp = ft_substr(str, 0, ft_strlen(str));
	node = ft_lstnew(str);
	if (!node)
	{
		clean_free(temp);
		clean_free(node);
		return ;
	}
	if (!ft_lstadd_back(lst, node))
	{
		clean_free(node->buffer);
		clean_free(node);
	}
}

t_list	*process_linked_list(t_list **lst, char *buffer)
{
	char	*str;
	char	*start;
	int		nl;

	str = ft_substr(buffer, 0, ft_strlen(buffer));
	start = str;
	while (*str)
	{
		nl = 0;
		if (*str == '\n')
		{
			string_into_linkedlist(lst, ft_substr(str, 0, 1));
			str++;
		}
		else
		{
			while (str[nl] && str[nl] != '\n')
				nl++;
			string_into_linkedlist(lst, ft_substr(str, 0, nl + 1));
			str += nl + 1;
		}
	}
	clean_free(start);
	return (*lst);
}

t_list	*read_to_nodes(int fd, size_t *total_bytes_read)
{
	char		*buffer;
	ssize_t		bytes_read;
	t_list		*start;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			clean_free(buffer);
			return (NULL);
		}
		else if (bytes_read == 0)
		{
			clean_free(buffer);
			break ;
		}
		buffer[bytes_read] = '\0';
		*total_bytes_read += bytes_read;
		start = process_linked_list(&start, buffer);
	}
	return (start);
}

char	*get_next_line(int fd)
{
	static t_list		*current_node;
	size_t				total_bytes_read;
	char				*line;

	total_bytes_read = 0;
	if (current_node == NULL)
	{
		if (fd <= -1 || fd == STDOUT_FILENO || fd == STDERR_FILENO
			|| read(fd, 0, 0) == -1 || BUFFER_SIZE <= 0)
			return (NULL);
		current_node = read_to_nodes(fd, &total_bytes_read);
		if (current_node == NULL)
			return (NULL);
	}
	if (current_node != NULL)
	{
		line = current_node->buffer;
		current_node = current_node->next;
		return (line);
	}
	else
		return (NULL);
}
