/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:52:12 by mtripodi          #+#    #+#             */
/*   Updated: 2024/07/24 12:53:46 by mtripodi         ###   ########.fr       */
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
 ** size_t read(int fildes, void *buf, size_t nbyte);
 **
 ** DESCRIPTION
 **     read() attempts to read nbyte bytes of data from the object referenced
 **     by the descriptor fildes size_to the buffer posize_ted to by buf.
 */

#include "libft.h"

static char	*get_freshline(char **sav)
{
	size_t		nl;
	char	*str;
	char	*strhead;
	char	*line;

	str = ft_substr(*sav, 0, ft_strlen(*sav));
	strhead = str;
	null_free(sav);
	nl = 0;
	while (str[nl] != '\0' && str[nl] != '\n')
		nl++;
	if (str[0] == '\n')
		line = ft_substr(str, 0, 1);
	else
		line = ft_substr(str, 0, nl + 1);
	if (nl > 0 && nl == ft_strlen(str))
		nl--;
	str += nl + 1;
	if (str)
		*sav = ft_substr(str, 0, ft_strlen(str));
	null_free(&strhead);
	strhead = NULL;
	return (line);
}

static char	*readtime(size_t fd, char *sav, char **buf, char *tmp)
{
	ssize_t			bytes_read;

	while (1)
	{
		bytes_read = read(fd, *buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		if (bytes_read == 0)
			break ;
		(*buf)[bytes_read] = '\0';
		tmp = sav;
		if (!tmp)
		{
			tmp = malloc(sizeof(char));
			if (tmp == NULL)
				return (NULL);
			tmp[0] = '\0';
		}
		sav = ft_strjoin(tmp, *buf);
		null_free(&tmp);
		if (ischar(sav, 0, '\n') == 1)
			break ;
	}
	null_free(buf);
	return (sav);
}

//  IMPORTANT NOTE
//      I kept making the mistake of having line 114 inside of line 111 if
//      statement. This meant that the read check would happen before buffer
//      was made, not allowing it to be free'd after the fact. Creating the
//      separate check for the file read error after line 134 passed the final
//      read errors.
char	*get_next_line(int fd)
{
	static char	*sav[256];
	char		*line;
	char		*buf;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 256)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (read(fd, 0, 0) == -1)
	{
		null_free(&buf);
		if (sav[fd])
			null_free(&sav[fd]);
		return (NULL);
	}
	if (buf == NULL)
		return (NULL);
	tmp = NULL;
	sav[fd] = readtime(fd, sav[fd], &buf, tmp);
	if (sav[fd] == NULL)
		return (NULL);
	line = get_freshline(&sav[fd]);
	return (line);
}
