/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 00:01:35 by mtripodi          #+#    #+#             */
/*   Updated: 2025/01/23 14:04:13 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	check_boarder(t_map *map, char **ber)
{
	int		row;
	int		col;


	while (col < map->height)
	{
		while(row < map->width)
		{
			mlx_put_image_to_window(app->mlx, app->win, img, row * 64,
				col * 64);
			row++;
			if ((col > 0 && row < map->width - 1) && col != map->height - 1)
				row = map->width - 1;
			else if (col > 0 && row >= map->width - 1 && col != map->height - 1)
				break ;
		}
		row = 0;
		col++;
	}
}

t_bool	keep_or_throw(t_map *map, char **ber)
{

}

t_map	*prepare_map(t_data *app, char *path)
{
	t_map		*map;

	map = app->map;
	map->txt = get_map(path);
	if (map->txt == NULL)
		ft_err("parse.c > prepare_map > get_map", app, 1);
	get_map_info(map);
	if (map->exits < 1 || map->exits > 1)
		ft_err("Only 1 Exit 'E' is allowed", app, 1);
	if (map->entry < 1 || map->entry > 1)
		ft_err("Only 1 Entry 'P' is allowed", app, 1);
	if (map->collect < 1)
		ft_err("Map needs one duckling 'C'", app, 1);
	if (map->height < 3 || map->width < 3 || map->height == map->width)
		ft_err("Map must be a rectangle and at least 3 tiles in height/width",
				 app, 1);
	if (check_boarder(map, map->txt) == false)
		ft_err("Map must be surrounded by Trees '1'", app, 1);
	if (keep_or_throw(map, map->txt) == true)
		return (map);
	else
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
	char		**map_txt;

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
	map_txt = ft_split(buf, '\n');
	free(buf);
	return (map_txt);
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
	map->width = ft_strlen(map->txt[0]);
	while (map->txt[y])
	{
		while (map->txt[y][x])
        {
            if (map->txt[y][x] == COLL)
                map->collect++;
            else if (map->txt[y][x] == DUCK)
				found_duck(map, x, y);
            else if (map->txt[y][x] == EXIT)
                map->exits++;
            x++;
        }
		x = 0;
		y++;
	}
	map->height = y;
}
