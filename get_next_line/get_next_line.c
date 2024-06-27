/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:10:32 by mtripodi          #+#    #+#             */
/*   Updated: 2024/06/28 08:53:45 by mtripodi         ###   ########.fr       */
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
   char	*bfrmalloc(char *sav)
   {
   char	*bfr;
   int	i;
   int	j;

   bfr = NULL;
   if (!sav)
   return (NULL);
   i = 0;
   j = 0;
   if (ischar(sav, 0, '\n') == 1)
   j++;
   while (sav[i] != '\n' && sav[i] != '\0')
   i++;
   bfr = malloc(sizeof(char) * (i + j + 1));
   if (bfr == NULL)
   return (NULL);
   return (bfr);
   }
 */
/*
   char	*bfrnewline(char *sav)
   {
   int		i;
   char	*bfr;

   if (!sav || sav[0] == '\0')
   return (NULL);
   bfr = bfrmalloc(sav);
   i = 0;
   while (sav[i] && sav[i] != '\n')
   {
   bfr[i] = sav[i];
   i++;
   }
   if (sav[0] == '\n')
   {
   bfr[i] = '\n';
   i++;
   }
   if (ischar(sav, 0, '\n') && sav[0] != '\n')
   i++;
   bfr[i] = '\0';
   return (bfr);
   }
 */

/*
   char	*aftnewline(char *sav)
   {
   int		i;
   int		j;
   char	*aft;

   if (!sav)
   return (NULL);
   if (ischar(sav, 1, '\n') == 0)
   {
   null_free(sav);
   return (NULL);
   }
   i = 0;
   while (sav[i] && sav[i] != '\n')
   i++;
   aft = malloc((sizeof(char) * (ft_strlen(sav) - i)));
   if (aft == NULL)
   return (NULL);
   i++;
   j = 0;
   while (sav[i])
   aft[j++] = sav[i++];
   aft[j] = '\0';
   null_free(sav);
   return (aft);
   }
 */
 
static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	i;

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
	size_t	nl;
	char	*str;
	char	*strhead;
	char	*line;

	str = ft_substr(*sav, 0, ft_strlen(*sav));
	strhead = str;
	null_free(*sav);
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
	*sav = ft_substr(str, 0, ft_strlen(str));
	null_free(strhead);
	strhead = NULL;
	return (line);
}
char	*readtime(int fd, char *sav, char *buf, char *tmp)
{
	ssize_t			bytes_read;

	while (1)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL); 
		if(bytes_read == 0)
			break ;
		buf[bytes_read] = '\0';
		tmp = sav;
		if (!tmp)
		{
			tmp = malloc(sizeof(char));
			if (tmp == NULL)
				return (NULL);
			tmp[0] = '\0';
		}
		sav = ft_strjoin(tmp, buf);
		null_free(tmp);
		if(ischar(sav, 0, '\n') == 1)
			break ;
	}
	null_free(buf);
	return (sav);
}

char	*get_next_line(int fd)
{
	static char *sav[OPEN_MAX];
	char				*line;
	char				*buf;
	char				*tmp;

	if (fd < 0 || read(fd, 0, 0) == -1 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	tmp = NULL;
	sav[fd] = readtime(fd, sav[fd], buf, tmp);
	if (sav[fd] == NULL)
		return (NULL);
	//bfr = bfrnewline(sav[fd]);
	//sav[fd] = aftnewline(sav[fd]);
	line = get_freshline(&sav[fd]);
	return (line);
}
