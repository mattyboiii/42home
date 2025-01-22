/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-22 07:02:57 by mtripodi          #+#    #+#             */
/*   Updated: 2025-01-22 07:02:57 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// char		check_tile(t_map *map, char **txt, t_duck duck)
// {
// 	if (txt[duck.y][duck.x] == 'C')
// 		map->collect;
// }

t_bool		collision_free(t_data *app, t_map *map, t_duck duck)
{
	char		c;

	if (duck.x > app->map->width || duck.y > app->map->height
			|| !duck.x || !duck.y)
		return (false);
	c = app->map->txt[duck.y][duck.x];
	if (c == TREE)
		return (false);
	else if (c == EXIT && duck.collected < map->collect)
		return (false);
	return (true);
}
/**
 * @brief Checks where the duck wants to move to. Used to check collision and
 * to check if any collectables are in the move. This function
 *
 * @param app the t_data struct
 * @param c   the key pressed to invoke the movement wsad
 * @return true/false depending on if the move is possible
 *
 */
t_bool	check_move(t_data *app, char c)
{
	t_duck		duck_future;

	duck_future = app->map->duck;
	if (c == 'w')
		duck_future.y--;
	else if (c == 's')
		duck_future.y++;
	else if (c == 'a')
		duck_future.x--;
	else if (c == 'd')
		duck_future.x++;
	return(collision_free(app, app->map, duck_future));
}
