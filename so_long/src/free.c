/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-19 20:24:19 by mtripodi          #+#    #+#             */
/*   Updated: 2025-01-19 20:24:19 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/** Functions here will have the sole purpose of freeing memory */

void	free_app(t_data *app)
{
	//
}

void	free_mlx(t_data *app)
{
	mlx_destroy_window(app->mlx, app->win);
	//mlx_destroy_image(app->mlx, app->img);
	mlx_destroy_display(app->mlx);
	free(app->mlx);
}
