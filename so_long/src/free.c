/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:24:19 by mtripodi          #+#    #+#             */
/*   Updated: 2025/01/30 17:45:52 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/** Functions here will have the sole purpose of freeing memory */

void	free_map(t_map	*map)
{
	if (map->ber)
		dp_free(&map->ber);
	free(map);
}

void	free_textures(t_data *app)
{
	int		i;

	i = 0;
	while (i <= 5)
	{
		if (app->textures[i])
		{
			mlx_destroy_image(app->mlx, app->textures[i]);
		}
		i++;
	}
}

void	free_mlx(t_data *app)
{
	mlx_destroy_window(app->mlx, app->win);
	mlx_destroy_display(app->mlx);
	free(app->mlx);
}

void	free_app(t_data *app)
{
	if (app->textures[0])
		free_textures(app);
	if (app->map)
		free_map(app->map);
	if (app->mlx)
		free_mlx(app);
	free(app);
}
