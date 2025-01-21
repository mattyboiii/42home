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
	while (m[col])
	{
		while(m[row])
		{
			img = mlx_xpm_file_to_image(app->mlx, app->textures[
				get_texture(m[col][row])], app->tile_size, app->tile_size);
			mlx_put_image_to_window(app->mlx, app->win, img, col * 64,
				row * 64);
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
	app->mlx = mlx_init();
	if (app->mlx == NULL)
		ft_err("inti_window > mlx_init: NULL", app, 1);
	app->win = mlx_new_window(app->mlx, app->map->width * 64,
			app->map->height * 64, "for DUCKS sake! - mtripodi");
	if (app->win == NULL)
		ft_err("init_window > mlx_new_window: NULL", app, 1);
	render_textures(app);
	place_textures(app);


}

