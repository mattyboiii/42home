/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:58:20 by mtripodi          #+#    #+#             */
/*   Updated: 2025/01/21 14:26:27 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	render_textures(t_data *app)
{
	app->textures[0] = mlx_xpm_file_to_image(app->mlx, "assets/grass.xpm",
				&app->tile_size, &app->tile_size);
	app->textures[1] = mlx_xpm_file_to_image(app->mlx, "assets/trees.xpm",
				&app->tile_size, &app->tile_size);
	app->textures[2] = mlx_xpm_file_to_image(app->mlx,
				"assets/duckling.xpm",
				&app->tile_size, &app->tile_size);
	app->textures[3] = mlx_xpm_file_to_image(app->mlx, "assets/exit.xpm",
				&app->tile_size, &app->tile_size);

	app->textures[4] = mlx_xpm_file_to_image(app->mlx, "assets/duck.xpm",
				&app->tile_size, &app->tile_size);
	app->textures[5] = NULL;
}
