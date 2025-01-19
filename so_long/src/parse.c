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



/**
 * @breif the ft_get_map reads the map putting each line
 * into a double pointer. This is done so I can later go through the contents
 * of the map to check if its valid, then push to screen.
 *
 * @param path
 * @return char **
*/
char	**get_map(char *path)
{
	int			fd;
	int			i;
	char		*buf;
	char		**map;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_err("Error opening file", 1);
	if (ft_read(fd, &buf) == -1)
		return (free(buf), NULL);
	while (buf[i])
	{
		if (buf[i] == '\n' && buf[i + 1] == '\n')
			return (free(buf), NULL);
		i++;
	}
	map = ft_split(buf, '\n');
	free(buf);
	return (map);
}

/**
 * @breif the get_map_info gets all the information about the map.
 * Why: So I can fill the map varialbe's with data relevant to the map
 *
 * @param map
*/
void	get_map_info(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	map->width = ft_strlen(map->txt[0]);
	while (map->txt[i])
	{
		while (map->txt[i][j])
		{
			if ((map->txt[i][j] == COLL && ++map->collect)
				|| (map->txt[i][j] == DUCK && ++map->entry)
				|| (map->txt[i][j] == EXIT && ++map->exits))
			if (map->txt[i][j] == DUCK)
				map->duck = (t_duck){j, i};
			j++;
		}
		i++;
	}
	map->height = i;
}
