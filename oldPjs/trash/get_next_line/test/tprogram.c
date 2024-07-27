/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tprogram.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 10:14:36 by mtripodi          #+#    #+#             */
/*   Updated: 2024/07/22 16:03:09 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "../get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = 0;
	fd = open("test/multiple_nlx5", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}
