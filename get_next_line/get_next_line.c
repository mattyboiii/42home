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

void	string_into_linkedlist(t_list **lst, char *str)
{
	t_list		*node;
	char		*temp;

	node = NULL;
	temp = ft_substr(str, 0, ft_strlen(str));
	node = malloc(sizeof(t_list));
	if (node == NULL)
	{
		free(temp);
		return ;
	}
	node->buffer = temp;
	node->next = NULL;
	if (!node)
	{
		free(temp);
		free(node);
		return ;
	}
	if (!ft_lstadd_back(lst, node))
	{
		free(node->buffer);
		free(node);
	}
}

t_list	*process_linked_list(t_list **lst, char *buffer)
{
	int		nl;

	while (*buffer)
	{
		nl = 0;
		if (*buffer == '\n')
		{
			string_into_linkedlist(lst, ft_substr(buffer, 0, 1));
			buffer++;
		}
		else
		{
			while (buffer[nl] && buffer[nl] != '\n')
				nl++;
			string_into_linkedlist(lst, ft_substr(buffer, 0, nl + 1));
			while (*buffer && nl-- > -1)
				buffer++;
		}
	}
	return (*lst);
}



t_list	*read_to_nodes(int fd, size_t *total_bytes_read)
{
	char		*buffer;
	ssize_t		bytes_read;
	t_list		*start;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (GNL_ERROR);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (GNL_ERROR);
		}
		else if (bytes_read == 0)
		{
			free(buffer);
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
	static t_list	*current_node;
	size_t		total_bytes_read;
	char		*line;

	total_bytes_read = 0;
	if (current_node == NULL)
	{
		if (fd <= -1 || fd == STDOUT_FILENO || fd == STDERR_FILENO
				|| read(fd, 0, 0) == -1 || BUFFER_SIZE <= 0)
			return (GNL_ERROR);
		current_node = read_to_nodes(fd, &total_bytes_read);
		if (current_node == NULL)
			return (GNL_ERROR);
		/*
		   current_node = process_nodes(current_node);
		   if (current_node == NULL)
		   return (GNL_ERROR);
		 */
	}
	if (current_node == NULL)
		return (GNL_ERROR);

	line = current_node->buffer;
	current_node = current_node->next;
	return (line);
}
