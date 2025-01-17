/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_movement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-17 06:16:26 by mtripodi          #+#    #+#             */
/*   Updated: 2025-01-17 06:16:26 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	move_up(t_data *app)
{
	int		mv;

	mv = 10;
	app->y -= mv;
	ft_memset(app->addr, 0, HEIGHT * WIDTH * (app->bits_per_pixel / 8));
	draw_circle(app, app->radius, ft_rgb(255, 0, 0));
	mlx_put_image_to_window(app->mlx, app->win, app->img, 0, 0);
}

int	move_right(t_data *app)
{
	int		mv;

	mv = 10;
	app->x += mv;
	ft_memset(app->addr, 0, HEIGHT * WIDTH * (app->bits_per_pixel / 8));
	draw_circle(app, app->radius, ft_rgb(255, 0, 0));
	mlx_put_image_to_window(app->mlx, app->win, app->img, 0, 0);
}

int	move_down(t_data *app)
{
	int		mv;

	mv = 10;
	app->y += mv;
	ft_memset(app->addr, 0, HEIGHT * WIDTH * (app->bits_per_pixel / 8));
	draw_circle(app, app->radius, ft_rgb(255, 0, 0));
	mlx_put_image_to_window(app->mlx, app->win, app->img, 0, 0);
}

int	move_left(t_data *app)
{
	int		mv;

	mv = 10;
	app->x -= mv;
	ft_memset(app->addr, 0, HEIGHT * WIDTH * (app->bits_per_pixel / 8));
	draw_circle(app, app->radius, ft_rgb(255, 0, 0));
	mlx_put_image_to_window(app->mlx, app->win, app->img, 0, 0);
}
