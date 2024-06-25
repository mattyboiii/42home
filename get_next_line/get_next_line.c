/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:10:32 by mtripodi          #+#    #+#             */
/*   Updated: 2024/06/25 16:14:34 by mtripodi         ###   ########.fr       */
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

char	*readtime(int fd, char sav, char buf, char tmp)
{
	int			bytes_read;

	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL); 
		buf[bytes_read] = '\0';
		tmp = str;
		if (!tmp)
		{
			tmp = malloc(sizeof(char));
			if (tmp == NULL)
				return (NULL);
			tmp[0] = '\0';
		}
		str = ft_strjoin(tmp, buf);

	}
}

char	*get_next_line(int fd)
{
	static char *sav[OPEN_MAX];
	char				*lin;
	char				*buf;
	char				*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	sav[fd] = readtime(fd, sav[fd], buf, tmp);
	return (NULL);
}
