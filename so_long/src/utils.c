/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-18 23:19:15 by mtripodi          #+#    #+#             */
/*   Updated: 2025-01-18 23:19:15 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

int	ft_read(int fd, char **line)
{
	int			bytes;
	char		c;
	char		*buffer;

	bytes = 0;
	if (fd < 0)
		return (-1);
	buffer = ft_calloc(100000, sizeof(char));
	if (!buffer)
		return (-1);
	while (read(fd, &c, 1) > 0 && c && bytes < 100000 - 1)
		buffer[bytes++] = c;
	buffer[bytes] = '\0';
	*line = buffer;
	return (bytes + 1);
}
int	ft_exit(int n)
{
	if (n == 2)
		ft_err("No map has been specified", n);
}

int	ft_err(char *msg, int n)
{
	char		*err_mes;

	err_mes = ft_strjoin("Error: ", msg);
	perror(err_mes);
	null_free(&err_mes);
	ft_exit(n);
}
