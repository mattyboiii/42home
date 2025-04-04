/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:09:15 by mtripodi          #+#    #+#             */
/*   Updated: 2025/02/04 16:14:58 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * check boarder is used to ensure the map is surrounded by '1's. This feat
 * took a little bit more code than the other map checks so needed its own
 * function. The map needs to be surrounded by trees as part of the requirment.
 */
t_bool	check_boarder(t_map *map, char **ber)
{
	int		row;
	int		col;

	col = 0;
	row = 0;
	while (row < map->height)
	{
		while (col < map->width)
		{
			if (ber[row][col] != '1')
				return (false);
			col++;
			if ((row > 0 && col < map->width - 1) && row != map->height - 1)
				col = map->width - 1;
			else if (row > 0 && col >= map->width - 1 && row != map->height - 1)
				break ;
		}
		col = 0;
		row++;
	}
	return (true);
}

/**
 * @brief this funciton is used to check if the characters inside of the map
 * are ONLY the ones inside of set. It uses ft_strchr to loop thorugh set
 * ensuring only allowed chars
 */
t_bool	check_map_chars(char **ber)
{
	int		row;
	int		col;
	char	*set;

	set = "01CEP";
	row = 0;
	col = 0;
	while (ber[row])
	{
		while (ber[row][col])
		{
			if (ber[row][col] && ft_strchr(set, ber[row][col]))
				col++;
			else
				return (false);
		}
		col = 0;
		row++;
	}
	return (true);
}

/**
 * @brief this function checks if the map is rectangle, or if all sides are
 * the same width
 */
t_bool	check_map_rectangle(char **ber)
{
	int		row;
	int		col;
	int		prev_col;

	row = 0;
	col = 0;
	prev_col = 0;
	while (ber[row])
	{
		while (ber[row][col])
		{
			if (row == 0)
				prev_col++;
			col++;
		}
		if (!prev_col || prev_col != col)
			return (false);
		col = 0;
		row++;
	}
	return (true);
}

/**
 * @brief function checks if the map path ends with .ber. in case the
 * second argument is maps, or any other directory name
 *
 * NOT ACTUALLY USING THIS???!?!?
 */
t_bool	check_filename(char *str)
{
	int		i;

	i = ft_strlen(str) - 4;
	if (i < 0)
		return (false);
	if (ft_strcmp(".ber", &str[i]) == 0)
		return (true);
	return (false);
}

/**
 * @brief check_map function checks the ber file for issues with the map. This
 * ensures maps are playable. Any issue with the map will be stated direclty
 */
void	check_map(t_data *app, t_map *map, char **ber)
{
	if (map->exits < 1)
		ft_err("Must be at least 1 Exit 'E' on the map", app, 1);
	if (map->exits > 1)
		ft_err("Only 1 Exit 'E' allowed on the map", app, 1);
	if (map->entry < 1)
		ft_err("Must be at least 1 Entry 'P' on the map", app, 1);
	if (map->entry > 1)
		ft_err("Only 1 Entry 'P' is allowed on the map", app, 1);
	if (map->collect < 1)
		ft_err("Map needs at least one Duckling 'C'", app, 1);
	if (map->height < 3 || map->width < 3 || map->height == map->width
		|| check_map_rectangle(ber) == false)
		ft_err("Map must be a rectangle and at least 3 tiles in height/width",
			app, 1);
	if (check_map_chars(ber) == false)
		ft_err("Map contains chars that are non allowed", app, 1);
	if (check_boarder(map, ber) == false)
		ft_err("Map must be completely surrounded by Trees '1'", app, 1);
}
