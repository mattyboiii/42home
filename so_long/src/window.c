/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:12:48 by mtripodi          #+#    #+#             */
/*   Updated: 2025/01/21 14:27:48 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void	place_textures(t_data *app)
{
	int		row;
	int		col;
	void	*img;
	char	**m;

	m = app->map->txt;
	row = 0;
	col = 0;
	while (col < app->map->height)
	{
		while(row < app->map->width)
		{
			ft_printf("col: %d, row: %d, m: %c\n", col, row, m[col][row]);
			img = app->textures[get_texture(m[col][row])];
			mlx_put_image_to_window(app->mlx, app->win, img, row * 64,
				col * 64);
			row++;
		}
		row = 0;
		col++;
	}

}

int	get_texture(char c)
{
	if (c == GRASS)
		return (0);
	else if (c == TREE)
		return (1);
	else if (c == COLL)
		return (2);
	else if (c == EXIT)
		return (3);
	else if (c == DUCK)
		return (4);
	return (0);
}


void	init_window(t_data *app)
{
	void	*img;

	app->mlx = mlx_init();
	if (app->mlx == NULL)
		ft_err("inti_window > mlx_init: NULL", app, 1);
	app->win = mlx_new_window(app->mlx, app->map->width * app->tile_size,
			app->map->height * app->tile_size, "for DUCKS sake! - mtripodi");
	if (app->win == NULL)
		ft_err("init_window > mlx_new_window: NULL", app, 1);
	render_textures(app);
	place_textures(app);
	ft_printf("hello");

}

