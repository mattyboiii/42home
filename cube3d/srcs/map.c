/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:27:00 by gcrisp            #+#    #+#             */
/*   Updated: 2025/04/24 15:11:03 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_map	*new_map(void)
{
	t_map	*out;

	out = malloc(sizeof(t_map));
	out->player_start = (t_point){0, 0};
	out->start_dir = -1;
	out->bounds = ft_vecnew(sizeof(t_boundary));
	out->wall_paths[NORTH] = 0;
	out->wall_paths[EAST] = 0;
	out->wall_paths[SOUTH] = 0;
	out->wall_paths[WEST] = 0;
	out->ciel_colour = 0xff000000;
	out->floor_colour = 0xff000000;
	return (out);
}

t_txt	*new_map_txt(void)
{
	t_txt	*out;

	out = malloc(sizeof(t_txt));
	out->txt = 0;
	out->height = 0;
	out->width = 0;
	out->entry = 0;
	return (out);
}

void	free_map_txt(t_txt *map)
{
	if (!map)
		return ;
	if (map->txt)
		ft_free_strs(map->txt);
}

void	free_map(t_map *map)
{
	if (!map)
		return ;
	if (map->bounds)
		ft_vecfree(&map->bounds, 0);
	free(map->wall_paths[NORTH]);
	free(map->wall_paths[EAST]);
	free(map->wall_paths[SOUTH]);
	free(map->wall_paths[WEST]);
	free(map);
}
