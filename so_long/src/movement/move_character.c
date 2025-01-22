/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 06:59:50 by mtripodi          #+#    #+#             */
/*   Updated: 2025/01/23 08:40:27 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_duck_exit(t_data *app, t_duck duck_next, t_duck duck_past)
{
	mlx_put_image_to_window(app->mlx, app->win, app->textures[4],
			duck_next.x * 64, duck_next.y * 64);
	mlx_put_image_to_window(app->mlx, app->win, app->textures[0],
			duck_past.x * 64, duck_past.y * 64);
	close_program(app);
}

void	move_duck_img(t_data *app, t_duck duck_next, t_duck duck_past)
{
	mlx_put_image_to_window(app->mlx, app->win, app->textures[4],
			duck_next.x * 64, duck_next.y * 64);
	mlx_put_image_to_window(app->mlx, app->win, app->textures[0],
			duck_past.x * 64, duck_past.y * 64);
}
