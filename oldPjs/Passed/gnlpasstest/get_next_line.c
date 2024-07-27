/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:47:52 by mtripodi          #+#    #+#             */
/*   Updated: 2024/07/25 16:09:00 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Function takes the input string and copies into a new string
// all chars that are before the new line and null terminator string
char	*ft_before(const char *str)
{
	int		i;
	char	*ptr;

	if (str == NULL || str[0] == '\0')
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	ptr = malloc((i + 1 + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		ptr[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		ptr[i] = '\n';
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// Function takes the input string and copies in a new string
// all chars that are after the new line and null terminator string
char	*ft_after(char *str)
{
	int		n;
	int		i;
	char	*ptr;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
	{
		null_free(&str);
		return (NULL);
	}
	n = ft_strlen(str);
	ptr = malloc((n - i) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	n = 0;
	i++;
	while (str[i] != '\0')
		ptr[n++] = str[i++];
	ptr[n] = '\0';
	null_free(&str);
	return (ptr);
}

int	ft_newline(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_read(int fd, char *buffer, char *tmp, char *str)
{
	int		bytes_read;

	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		buffer[bytes_read] = '\0';
		tmp = str;
		if (tmp == NULL)
		{
			tmp = malloc(sizeof(char));
			if (tmp == NULL)
				return (NULL);
			tmp[0] = '\0';
		}
		str = ft_strjoin(tmp, buffer);
		null_free(&tmp);
		if (ft_newline(str) == 1 || bytes_read == 0)
			break ;
	}
	null_free(&buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*sav;
	char		*buffer;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 256)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (read(fd, 0, 0) == -1)
	{
		null_free(&buffer);
		if (sav)
			null_free(&sav);
		return (NULL);
	}
	if (buffer == NULL)
		return (NULL);
	tmp = NULL;
	sav = ft_read(fd, buffer, tmp, sav);
	if (sav == NULL)
		return (NULL);
	line = ft_before(sav);
	sav = ft_after(sav);
	return (line);
}
