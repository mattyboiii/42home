/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:12:48 by mtripodi          #+#    #+#             */
/*   Updated: 2025/01/23 11:48:42 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_win(t_data *app, t_map *map)
{
	int		row;
	int		col;
	void	*img;

	img = mlx_xpm_file_to_image(app->mlx, "assets/win.xpm", &app->tile_size,
				&app->tile_size);
	row = 0;
	col = 0;
	while (col < map->height)
	{
		while(row < map->width)
		{
			mlx_put_image_to_window(app->mlx, app->win, img, row * 64,
				col * 64);
			row++;
			if ((col > 0 && row < map->width - 1) && col != map->height - 1)
				row = map->width - 1;
			else if (col > 0 && row >= map->width - 1 && col != map->height - 1)
				break ;
		}
		row = 0;
		col++;
	}
}

/** @brief place_textures is responsible for reading the map_ber and placing
 * the correct texture at their correct spot.
 *
 * @param t_data
*/
void	place_textures(t_data *app, char **m)
{
	int		row;
	int		col;
	void	*img;

	row = 0;
	col = 0;
	while (col < app->map->height)
	{
		while(row < app->map->width)
		{
			img = app->textures[get_texture(m[col][row])];
			mlx_put_image_to_window(app->mlx, app->win, img, row * 64,
				col * 64);
			row++;
		}
		row = 0;
		col++;
	}
}

void	init_window(t_data *app)
{
	void	*img;

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

