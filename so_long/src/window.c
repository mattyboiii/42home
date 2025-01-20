/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:12:48 by mtripodi          #+#    #+#             */
/*   Updated: 2025/01/20 15:00:17 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_data *app)
{
	app->mlx = mlx_init();
	if (app->mlx == NULL)
		ft_err("mlx_init", 1);
	app->win = mlx_new_window(app->mlx, app->map->width * TILE_SIZE,
			app->map->height * TILE_SIZE, "for DUCKS sake! - mtripodi");
	if (app->win == NULL)
	{
		free_mlx(app);
		ft_err("app->win", 1);
	}

}
