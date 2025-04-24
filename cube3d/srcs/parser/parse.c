/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 00:01:35 by mtripodi          #+#    #+#             */
/*   Updated: 2025/04/24 14:54:18 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

/**
 * @brief the ft_err function is mainly responsible for printing function
 * dedicated errors to stderr during an error.
 *
 * It will also free the app assuming its passed in.
 *
 * It can also exit the program assuming that you have supplied a number > 0.
 *
 *
 * @param char *msg, t_data *app, int n
 * @return 0
*/
void	ft_err(char *msg, t_data *app, int n)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	if (app)
		free_app(app);
	if (n > 0)
		exit(n);
}

/**
 * @brief prepare_map is used to run the map functions to create it. It
 * will return a map pointer.
 */
void	*prepare_map( *path)
{
	char		**ber_copy;
	t_map		*map;

	map = app->map;
	map->ber = get_map(path);
	if (map->ber == NULL || map->ber[0] == NULL)
		ft_err("Failed to read map, Check Specified map Path", app, 1);
	get_map_info(map);
	check_map(map->ber);
	ber_copy = get_map(path);
	if (valid_map_path(map, map->duck.x, map->duck.y, &flood) == false)
	{
		dp_free(&ber_copy);
		ft_err("Map is not possible, no valid path for our Duck", app, 1);
	}
	dp_free(&app->map->ber);
	app->map->ber = ber_copy;
	return (map);
}

/**
 * @brief the ft_get_map reads the map putting each line
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
	{
		return (NULL);
	}
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
 * @brief the get_map_info gets all the information about the map.
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
			x++;
		x = 0;
		y++;
	}
	map->height = y;
}
