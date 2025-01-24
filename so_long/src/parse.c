/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 00:01:35 by mtripodi          #+#    #+#             */
/*   Updated: 2025/01/23 17:15:32 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


t_bool	valid_map_path(t_map *map, int row, int col, t_flood *flood)
{
	if (flood->collected == map->collect && flood->exits == 1)
		return (true);
	if (map->ber[col][row] == TREE)
		return (false);
	if (map->ber[col][row] == COLL)
		flood->collected++;
	if (map->ber[col][row] == EXIT)
		flood->exits++;
	map->ber[col][row] = TREE;
	if (valid_map_path(map, row + 1, col, flood) == true
		|| valid_map_path(map, row - 1, col, flood) == true
		|| valid_map_path(map, row, col + 1, flood) == true
		|| valid_map_path(map, row, col - 1, flood) == true)
		return (true);
	return (false);
}

t_map	*prepare_map(t_data *app, char *path)
{
	t_map		*map;
	t_flood		flood;

	map = app->map;
	map->ber = get_map(path);
	if (map->ber == NULL)
		ft_err("parse.c > prepare_map > get_map", app, 1);
	get_map_info(map);
	flood.collected = 0;
	flood.exits = 0;
	valid_map_path(map, app->map->duck.x, app->map->duck.y, &flood);
	return (NULL);
}

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
	char		**map_ber;

	buf = NULL;
	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ft_err("parse.c > get_map > open", 0, 0), NULL);
	if (ft_read(fd, &buf) == -1)
		return (free(buf), NULL);
	while (buf[i])
	{
		if (buf[i] == '\n' && buf[i + 1] == '\n')
			return (free(buf), NULL);
		i++;
	}
	map_ber = ft_split(buf, '\n');
	free(buf);
	return (map_ber);
}

/**
 * @breif the get_map_info gets all the information about the map.
 * Why: So I can fill the map varialbe's with data relevant to the map
 *
 * @param map
*/
void	get_map_info(t_map *map)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	map->width = ft_strlen(map->ber[0]);
	while (map->ber[y])
	{
		while (map->ber[y][x])
        {
            if (map->ber[y][x] == COLL)
                map->collect++;
            else if (map->ber[y][x] == DUCK)
				found_duck(map, x, y);
            else if (map->ber[y][x] == EXIT)
                map->exits++;
            x++;
        }
		x = 0;
		y++;
	}
	map->height = y;
}
