/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 07:02:48 by mtripodi          #+#    #+#             */
/*   Updated: 2025/01/28 14:58:59 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief this function is used to change the coordinates of the duck depending
 * on the direction. Keep track of the previous locaiton of the duck. Check
 * if the duck has hit any collectables, and then call the appropriate move_img
 * function depending on where the duck moved to.
 *
 * The move functions also check's the victory state, because if the player has
 * already won, it will dispaly a victory message. The function will not be
 * called again after this.
 *
 * All move funciton are the same its only the direciton that changes.
 */
int	move_up(t_data *app, t_map *map, t_duck *duck)
{
	t_duck		duck_past;

	map->moves++;
	duck_past = *duck;
	duck->y--;
	if (map->ber[duck->y][duck->x] == 'C')
		duck->collected++;
	if (map->ber[duck->y][duck->x] == 'E')
		move_duck_exit(app, *duck, duck_past);
	move_duck_img(app, *duck, duck_past);
	if (app->victory == 1)
	{
		ft_printf("Moves: %d\n", map->moves);
		ft_putendl_fd("Victory!!! Well Ducking Done :)", 1);
		ft_putendl_fd("Press ANY key to close", 1);
	}
	else
		ft_printf("Moves: %d\n", map->moves);
	return (0);
}

int	move_down(t_data *app, t_map *map, t_duck *duck)
{
	t_duck		duck_past;

	map->moves++;
	duck_past = *duck;
	duck->y++;
	if (map->ber[duck->y][duck->x] == 'C')
		duck->collected++;
	if (map->ber[duck->y][duck->x] == 'E')
		move_duck_exit(app, *duck, duck_past);
	move_duck_img(app, *duck, duck_past);
	if (app->victory == 1)
	{
		ft_printf("Moves: %d\n", map->moves);
		ft_putendl_fd("Victory!!! Well Ducking Done :)", 1);
		ft_putendl_fd("Press ANY key to close", 1);
	}
	else
		ft_printf("Moves: %d\n", map->moves);
	return (0);
}

int	move_left(t_data *app, t_map *map, t_duck *duck)
{
	t_duck		duck_past;

	map->moves++;
	duck_past = *duck;
	duck->x--;
	if (map->ber[duck->y][duck->x] == 'C')
		duck->collected++;
	if (map->ber[duck->y][duck->x] == 'E')
		move_duck_exit(app, *duck, duck_past);
	move_duck_img(app, *duck, duck_past);
	if (app->victory == 1)
	{
		ft_printf("Moves: %d\n", map->moves);
		ft_putendl_fd("Victory!!! Well Ducking Done :)", 1);
		ft_putendl_fd("Press ANY key to close", 1);
	}
	else
		ft_printf("Moves: %d\n", map->moves);
	return (0);
}

int	move_right(t_data *app, t_map *map, t_duck *duck)
{
	t_duck		duck_past;

	map->moves++;
	duck_past = *duck;
	duck->x++;
	if (map->ber[duck->y][duck->x] == 'C')
		duck->collected++;
	if (map->ber[duck->y][duck->x] == 'E')
		move_duck_exit(app, *duck, duck_past);
	move_duck_img(app, *duck, duck_past);
	if (app->victory == 1)
	{
		ft_printf("Moves: %d\n", map->moves);
		ft_putendl_fd("Victory!!! Well Ducking Done :)", 1);
		ft_putendl_fd("Press ANY key to close", 1);
	}
	else
		ft_printf("Moves: %d\n", map->moves);
	return (0);
}
