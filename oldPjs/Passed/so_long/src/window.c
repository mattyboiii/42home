/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:12:48 by mtripodi          #+#    #+#             */
/*   Updated: 2025/01/30 18:24:20 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief place windows is responsible for placing the "win" image around the
 * boarder of the map. This is just a way for me to demonstrate to the player
 * they have won the game.
 */
void	place_win(t_data *app, t_map *map)
{
	int		col;
	int		row;
	void	*img;

	img = mlx_xpm_file_to_image(app->mlx, "textures/win.xpm", &app->tile_size,
			&app->tile_size);
	col = 0;
	row = 0;
	while (row < map->height)
	{
		while (col < map->width)
		{
			mlx_put_image_to_window(app->mlx, app->win, img, col * 64,
				row * 64);
			col++;
			if ((row > 0 && col < map->width - 1) && row != map->height - 1)
				col = map->width - 1;
			else if (row > 0 && col >= map->width - 1 && row != map->height - 1)
				break ;
		}
		col = 0;
		row++;
	}
	mlx_destroy_image(app->mlx, img);
}

/** @brief place_textures is responsible for reading the map_ber and placing
 * the correct texture at their correct spot.
 *
 * @param t_data
*/
void	place_textures(t_data *app, char **m)
{
	int		col;
	int		row;
	void	*img;

	col = 0;
	row = 0;
	while (row < app->map->height)
	{
		while (col < app->map->width)
		{
			img = app->textures[get_texture(m[row][col])];
			mlx_put_image_to_window(app->mlx, app->win, img, col * 64,
				row * 64);
			col++;
		}
		col = 0;
		row++;
	}
}

/**
 * @brief init window function is responsible for creating the window where
 * the program will run. It is also responsible for promting render_textures
 * along with placing the innitial map images to the windows.
 */
void	init_window(t_data *app)
{
	app->mlx = mlx_init();
	if (app->mlx == NULL)
		ft_err("inti_window > mlx_init: NULL", app, 1);
	app->win = mlx_new_window(app->mlx, app->map->width * app->tile_size,
			app->map->height * app->tile_size,
			"for DUCKS sake! - mtripodi");
	if (app->win == NULL)
		ft_err("init_window > mlx_new_window: NULL", app, 1);
	render_textures(app);
	place_textures(app, app->map->ber);
}
