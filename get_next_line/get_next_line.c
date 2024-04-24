/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:10:32 by mtripodi          #+#    #+#             */
/*   Updated: 2024/04/24 12:01:49 by mtripodi         ###   ########.fr       */
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

static t_list	*newline_nodes(t_list **lst, char *buffer)
{
	t_list	*head;
	char	*str;
	size_t	nl;

	head = *lst;
	str = buffer;
	while (*str)
	{
		nl = 0;
		if (*str == '\n')
		{
			head = string_into_linkedlist(&head, (ft_substr(str, 0, 1)));
			return(head);
		}
		else
		{
			while (str[nl] != '\0' && str[nl] != '\n')
				nl++;
			head = string_into_linkedlist(&head, (ft_substr(str, 0, nl + 1)));
			if (nl == ft_strlen(str))
				nl--;
			str += nl + 1;
		}
	}
	return (head);
}

static void	update_node_buffer(t_list **lst, char *buffer)
{
	char	*new_buffer;
	t_list	*head;
	t_list	*prevnode;

	prevnode = NULL;
	head = *lst;
	if (!*lst)
	{
		*lst = newline_nodes(&(*lst), buffer);
		return ;
	}
	while (*lst && (*lst)->next != NULL)
	{
		prevnode = *lst;
		*lst = (*lst)->next;
	}
	new_buffer = ft_strjoin((*lst)->buffer, (char *)buffer);
	ft_lstclear(&(*lst), &prevnode, free);
	*lst = NULL;
	if (prevnode != NULL)
		*lst = prevnode;
	*lst = newline_nodes(&(*lst), new_buffer);
	free(new_buffer);
	if (prevnode != NULL)
		*lst = head;
}

static t_list	*read_to_nodes(int fd, size_t *total_b_re, t_list **head)
{
	char		*buffer;
	ssize_t		bytes_read;

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
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		*total_b_re += bytes_read;
		update_node_buffer(head, buffer);
	}
	free(buffer);
	return (*head);
}

char	*get_next_line(int fd)
{
	static t_list		*head;
	t_list				*current;
	char				*line;
	size_t				total_b_re;

	total_b_re = 0;
	if (head == NULL)
	{
		if (fd < 0 || BUFFER_SIZE <= 0)
			return (NULL);
		head = NULL;
		head = read_to_nodes(fd, &total_b_re, &head);
		if (head == NULL)
			return (NULL);
		current = head;
	}
	if (head)
	{
		current = head;
		line = current->buffer;
		head = head->next;
		free(current);
		return (line);
	}
	return (NULL);
}
