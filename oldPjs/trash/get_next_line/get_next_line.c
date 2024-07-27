/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:45:02 by mtripodi          #+#    #+#             */
/*   Updated: 2024/07/24 12:47:59 by mtripodi         ###   ########.fr       */
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
 ** int read(int fildes, void *buf, int nbyte);
 **
 ** DESCRIPTION
 **     read() attempts to read nbyte bytes of data from the object referenced
 **     by the descriptor fildes into the buffer pointed to by buf.
 */

#include "get_next_line.h"

static char	*ft_substr(char const *s, int start, int len)
{
	char	*out;
	int		i;

	i = 0;
	if (!s || start >= ft_strlen(s))
		return (NULL);
	if ((ft_strlen(s) - start) < len)
		len = ft_strlen(s) - start;
	out = malloc((sizeof(char)) * (len + 1));
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

static char	*get_freshline(char **sav)
{
	int		nl;
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

static char	*readtime(int fd, char *sav, char **buf, char *tmp)
{
	int			bytes_read;

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
//      I kept making the mistake of having line 135 inside of line 132 if
//      statement. This meant that the read check would happen before buffer
//      was made, not allowing it to be free'd after the fact. Creating the
//      separate check for the file read error after line 134 passed the final
//      read errors.
char	*get_next_line(int fd)
{
	static char	*sav;
	char		*line;
	char		*buf;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 256)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (read(fd, 0, 0) == -1)
	{
		null_free(&buf);
		if (sav)
			null_free(&sav);
		return (NULL);
	}
	if (buf == NULL)
		return (NULL);
	tmp = NULL;
	sav = readtime(fd, sav, &buf, tmp);
	if (sav == NULL)
		return (NULL);
	line = get_freshline(&sav);
	return (line);
}
