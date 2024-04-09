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

ssize_t	read_bytes(int fd, char *buffer, t_list *head)
{
	ssize_t		bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		free(buffer);
		ft_lstclear(&head, delete_content); 
		return (-1);
	}
	else if (bytes_read == 0)
	{
		free(buffer);
		return (0);
	}

	buffer[bytes_read] = '\0';
	return (bytes_read);

}

t_list	*read_to_node(int fd, size_t *total_bytes_read)
{
	char		*buffer;
	ssize_t		bytes_read;
	t_list		*head;

	head = NULL;
	*total_bytes_read = 0;
	while ((buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))) != NULL)
	{
		if (buffer == NULL)
			return (NULL);
		bytes_read = read_bytes(fd, buffer, head);
		if (bytes_read == -1)
			return (NULL);
		else if (bytes_read == 0)
			break;
		*total_bytes_read += bytes_read;
		if (!ft_lstadd_back(&head, ft_lstnew(buffer)))
		{
			ft_lstclear(&head, free);
			return (NULL);
		}

	}
	return (head);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	t_list		*head;
	size_t		*total_bytes_read;

	// Check if the file descriptor is valid
	if (fd <= -1 || fd == STDOUT_FILENO || fd == STDERR_FILENO || fd >= OPEN_MAX
			|| read(fd, 0, 0) == -1 || BUFFER_SIZE <= 0)
		return (GNL_ERROR);

	// Allocate memory for the buffer to read data from the file
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (GNL_ERROR);


	// Loop to read data from the file and process it line by line

	head = read_to_node(fd, total_bytes_read);
			// You might use a while loop that continues until the end of file or an error occurs

			// Read data from the file into the buffer
			// Check for errors during reading and handle them appropriately

			// Process the buffer to find complete lines of text
			// You might need to handle cases where lines span multiple chunks

			// Create a new node in the linked list and store the complete line of text in it
			// Update pointers as necessary to manage the linked list

			// Check if a complete line has been found and return it if so

			// Free memory allocated for the buffer and any remaining nodes in the linked list
			// Handle any cleanup operations before returning

			// Return NULL to indicate that the end of file has been reached or an error occurred


			}
