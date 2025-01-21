/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:12:48 by mtripodi          #+#    #+#             */
/*   Updated: 2025/01/21 11:26:11 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void	place_textures(t_data *app)
{
	int		row;
	int		col;
	char	**m;

	m = app->map->txt;
	row = 0;
	col = 0;
	while (m[col])
	{
		while(m[row])
		{
			
		}
	}



}


void	init_window(t_data *app)
{
	app->mlx = mlx_init();
	if (app->mlx == NULL)
		ft_err("inti_window > mlx_init: NULL", app, 1);
	app->win = mlx_new_window(app->mlx, app->map->width * TILE_SIZE,
			app->map->height * TILE_SIZE, "for DUCKS sake! - mtripodi");
	if (app->win == NULL)
		ft_err("init_window > mlx_new_window: NULL", app, 1);
	render_textures(app);
	place_textures(app);


}

