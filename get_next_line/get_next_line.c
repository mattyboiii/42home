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

static char	*update_node(t_list **lst, char *buffer, t_list **footnode)
{
	char	*new_buffer;

	new_buffer = buffer;
	if (!*lst)
		*lst = (NULL);
	if (!buffer && *lst)
	{
		*footnode = *lst;
		return (NULL);
	}
	while (*lst != NULL && (*lst)->next != NULL)
		*lst = (*lst)->next;
	if (*lst && (*lst)->buffer)
	{
		if ((*lst)->buffer[ft_strlen((*lst)->buffer) - 1] != '\n')
		{
			new_buffer = ft_strjoin((*lst)->buffer, (char *)buffer);
			if (!new_buffer)
				return (NULL);
			free((*lst)->buffer);
		}
	}
	*footnode = *lst;
	return (new_buffer);
}

static t_list	*newline_nodes(t_list **lst, char *buffer)
{
	t_list	*footnode;
	t_list	*head;
	char	*str;
	size_t	nl;
	
	head = *lst;
	str = update_node(lst, buffer, &footnode);
	while (*str)
	{
		nl = 0;
		if (*str == '\n')
			footnode->next = ft_lstnew(ft_substr(str, 0, 1));
		else
		{
			while (str[nl] && str[nl] != '\n')
				nl++;
			footnode = ft_lstnew(ft_substr(str, 0, nl + 1));
			str += nl + 1;
		}
		if (!*lst)
			head = footnode;
		footnode = footnode->next;
	}
	return (head);
}

static t_list	*read_to_nodes(int fd, size_t *total_bytes_read, t_list **head)
{
	char		*buffer;
	int			bytes_read;

	bytes_read = 0;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			ft_lstclear(head, free);
			free(buffer);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		*total_bytes_read += bytes_read;
		*head = newline_nodes(head, buffer);
	}
	free(buffer);
	return (*head);
}

char	*get_next_line(int fd)
{
	static t_list		*head;
	size_t				total_bytes_read;
	char				*line;

	head = NULL;
	total_bytes_read = 0;
	if (head == NULL)
	{
		if (fd < 0 || BUFFER_SIZE <= 0)
			return (NULL);
		head = read_to_nodes(fd, &total_bytes_read, &head);
		if (head == NULL)
			return (NULL);
	}
	if (head)
	{
		line = head->buffer;
		head = head->next;
		return (line);
	}
	ft_lstclear(&head, free);
	return (NULL);
}
