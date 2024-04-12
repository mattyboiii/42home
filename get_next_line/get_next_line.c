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
	temp = ft_strdup(str);
	node = ft_lstnew((char *)temp);
	if (!node)
	{
		free(temp);
		return ;
	}
	if (!ft_lstadd_back(lst, node))
	{
		ft_lstclear(&node, delete_content);
	}
}

t_list	*process_nodes(t_list *lst)
{
	char		*tmp;
	char		*afternextline;
	int		nextline;
	t_list		*freshlines;

	freshlines = NULL;
	while (lst)
	{
		nextline = 0;
		if (afternextline)
			ft_strcatmal(afternextline, lst->buffer, tmp); 
		else
			tmp = lst->buffer;
		free(afternextline);
		nextline = ft_strlen(tmp);
		while (tmp[nextline] != '\n' && nextline >= 0)
			nextline--;
		if (tmp[nextline] == '\n')
		{
			string_into_linkedlist(&freshlines, (ft_substr(tmp, 0,
			nextline))); 
		}
		while (tmp[nextline] == '\n')
			nextline++;
		afternextline = NULL;
		if (tmp[nextline + 1])
			afternextline = ft_substr(tmp, nextline, ft_strlen(tmp)); 
		tmp = NULL;
		free(tmp);
		lst = lst->next;
	}
	free(tmp);
	free(afternextline);
	return (freshlines);
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
		string_into_linkedlist(&start, buffer);
	}
	return (start);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	t_list		*head;
	size_t		total_bytes_read;

	total_bytes_read = 0;
	// Check if the file descriptor is valid
	if (fd <= -1 || fd == STDOUT_FILENO || fd == STDERR_FILENO
			|| read(fd, 0, 0) == -1 || BUFFER_SIZE <= 0)
		return (GNL_ERROR);

	// Allocate memory for the buffer to read data from the file
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (GNL_ERROR);
	head = read_to_nodes(fd, &total_bytes_read);
	// Process the buffer to find complete lines of text

	head = process_nodes(head);

	// You might need to handle cases where lines span multiple chunks

	// Update pointers as necessary to manage the linked list

	// Check if a complete line has been found and return it if so

	// Free memory allocated for the buffer and any remaining nodes in 
	// the linked list
	// Handle any cleanup operations before returning

	// Return NULL to indicate that the end of file has been reached or 
	// an error occurred
	return (head->buffer);
}
