/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:12:48 by mtripodi          #+#    #+#             */
/*   Updated: 2025/01/23 08:49:21 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_scoreboard(t_data *app, t_map *map, char **m)
{
	int		row;
	int		col;
	void	*img;

	row = 0;
	col = map->height;
	while (col <= app->map->height)
	{
		while(row < app->map->width)
		{
			ft_printf("col: %d, row: %d\n", col, row);
			img = app->textures[0];
			mlx_put_image_to_window(app->mlx, app->win, img, row * 64,
				col * 64);
			row++;
		}
		row = 0;
		col++;
	}
}

/** @breif place_textures is responsible for reading the map_txt and placing
 * the correct texture at their correct spot.
 *
 * @param t_data* */
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
			ft_printf("col: %d, rows %d, m: %c\n", col, row, m[col][row]);
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
	place_textures(app, app->map->txt);
	place_scoreboard(app, app->map, app->map->txt);
}

