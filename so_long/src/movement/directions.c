/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-22 07:02:48 by mtripodi          #+#    #+#             */
/*   Updated: 2025-01-22 07:02:48 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_duck_img(t_data *app, t_duck duck_next, t_duck duck_past)
{
	mlx_put_image_to_window(app->mlx, app->win, app->textures[4],
			duck_next.x * 64, duck_next.y * 64);
	mlx_put_image_to_window(app->mlx, app->win, app->textures[0],
			duck_past.x * 64, duck_past.y * 64);
}

int	move_up(t_data *app, t_map *map, t_duck *duck)
{
	char		prev_tile;
	t_duck		duck_past;

	duck_past = *duck;
	duck->y--;
	if (map->txt[duck->y][duck->x] == 'C')
		duck->collected++;
	move_duck_img(app, *duck, duck_past);
	return (0);
}

int	move_down(t_data *app, t_map *map, t_duck *duck)
{
	t_duck		duck_past;

	duck_past = *duck;
	duck->y++;
	if (map->txt[duck->y][duck->x] == 'C')
		duck->collected++;
	move_duck_img(app, *duck, duck_past);
	return (0);
}

int	move_left(t_data *app, t_map *map, t_duck *duck)
{
	t_duck		duck_past;

	duck_past = *duck;
	duck->x--;
	if (map->txt[duck->y][duck->x] == 'C')
		duck->collected++;
	move_duck_img(app, *duck, duck_past);
	return (0);
}

int	move_right(t_data *app, t_map *map, t_duck *duck)
{
	t_duck		duck_past;

	duck_past = *duck;
	duck->x++;
	if (map->txt[duck->y][duck->x] == 'C')
		duck->collected++;
	move_duck_img(app, *duck, duck_past);
	return (0);
}


