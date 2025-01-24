/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:09:15 by mtripodi          #+#    #+#             */
/*   Updated: 2025/01/23 17:15:38 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	check_boarder(t_map *map, char **ber)
{
	int		row;
	int		col;

	row = 0;
	col = 0;
	while (col < map->height)
	{
		while(row < map->width)
		{
			if (ber[col][row] != '1')
				return (false);
			row++;
			if ((col > 0 && row < map->width - 1) && col != map->height - 1)
				row = map->width - 1;
			else if (col > 0 && row >= map->width - 1 && col != map->height - 1)
				break ;
		}
		row = 0;
		col++;
	}
	return (true);
}

t_bool	check_map(t_data *app, t_map *map, char **ber)
{
	if (map->exits < 1 || map->exits > 1)
		ft_err("Only 1 Exit 'E' is allowed", app, 1);
	if (map->entry < 1 || map->entry > 1)
		ft_err("Only 1 Entry 'P' is allowed", app, 1);
	if (map->collect < 1)
		ft_err("Map needs one duckling 'C'", app, 1);
	if (map->height < 3 || map->width < 3 || map->height == map->width)
		ft_err("Map must be a rectangle and at least 3 tiles in height/width",
				 app, 1);
	if (check_boarder(map, map->ber) == false)
		ft_err("Map must be surrounded by Trees '1'", app, 1);
	if (valid_path(map, map->ber, map->duck) == true)
		return (map);
}
