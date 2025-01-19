/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-19 00:01:35 by mtripodi          #+#    #+#             */
/*   Updated: 2025-01-19 00:01:35 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_map(char *path)
{
	int			fd;
	char		*buf;
	char		**map;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_err("Error opening file", 1);
	if (ft_read(fd, &buf) == -1)
	{
		free(buf);
		return (NULL);
	}

}
