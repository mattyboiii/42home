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
/*
   t_lit	process_nodes(t_list *head)
   {
   char	*tmp;
   char	*line;
   int	nextline;

   nextline = 0;
//look inside of the first node and make tmp =  head->buffer
tmp = head->buffer;
while (*tmp != '\n' || *tmp != '\0' && nextline <= BUFFER_SIZE)
nextline++;


}
 */

/*
void	null_free(char *ptr)
{
	free(ptr);
	ptr = NULL;
}
*/

t_list	*read_to_node(int fd, size_t *total_bytes_read)
{
	char		*buffer;
	char		*tempbuff;
	ssize_t		bytes_read;
	t_list		*node;
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
			return (NULL);
		}
		else if (bytes_read == 0)
		{
			free(buffer);
			free(tempbuff);
			break ;
		}
		buffer[bytes_read] = '\0';
		*total_bytes_read += bytes_read;
		tempbuff = ft_strdup(buffer);
		node = ft_lstnew((char*)tempbuff);
		if (!ft_lstadd_back(&start, node))
		{
			ft_lstclear(&node, delete_content);
			return (NULL);
		}
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
	head = read_to_node(fd, &total_bytes_read);
	// Process the buffer to find complete lines of text

	// head = process_nodes(head);

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
