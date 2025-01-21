/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:58:20 by mtripodi          #+#    #+#             */
/*   Updated: 2025/01/21 11:11:31 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_textures(t_data *app)
{
	app->textures[0] = mlx_xpm_file_to_image(app->mlx, "../assets/grass.xpm",
				TILE_SIZE, TILE_SIZE);
	app->textures[1] = mlx_xpm_file_to_image(app->mlx, "../assets/tree.xpm",
				TILE_SIZE, TILE_SIZE);
	app->textures[2] = mlx_xpm_file_to_image(app->mlx,
				"../assets/duckling.xpm",
				TILE_SIZE, TILE_SIZE);
	app->textures[3] = mlx_xpm_file_to_image(app->mlx, "../assets/exit.xpm",
				TILE_SIZE, TILE_SIZE);

	app->textures[4] = mlx_xpm_file_to_image(app->mlx, "../assets/tree.xpm",
				TILE_SIZE, TILE_SIZE);
	app->textures[5] = NULL;
}
