/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duck.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-22 05:19:34 by mtripodi          #+#    #+#             */
/*   Updated: 2025-01-22 05:19:34 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	found_duck(t_map *map, int x, int y)
{
	if (!map->duck.x && !map->duck.y)
	{
		map->duck.x = x;
		map->duck.y = y;
		map->entry++;
	}
	else
		map->entry++;
}
