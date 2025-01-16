/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 00:59:25 by mtripodi          #+#    #+#             */
/*   Updated: 2025-01-14 00:59:25 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	height_x_length(t_app *app, int height, int length)
{
		int		stop;
		int		colour;
		int		x = 5;
		int		y = 5;

		colour = 0xFFFF0000;
		stop = 0;

		while (stop < height)
		{
			ft_mlx_pix_put(&app->img, x, y + stop, colour);
			ft_mlx_pix_put(&app->img, x + length, y + stop, colour);
			mlx_put_image_to_window(app->mlx, app->win, app->img.res, 0, 0);
			stop++;
		}
		stop = 0;
		while (stop < length)
		{
			ft_mlx_pix_put(&app->img, x + stop, y, colour);
			ft_mlx_pix_put(&app->img, x + stop, y + length, colour);
			mlx_put_image_to_window(app->mlx, app->win, app->img.res, 0, 0);
			stop++;
		}
}

int	main(void)
{
	t_app 		app;

	//create a structure which holds all the ptr's available to use and run
	// MiniLibx
	app.mlx = mlx_init();
	if (app.mlx == NULL)
		return (1);

	// create my first window
	app.win = mlx_new_window (app.mlx, 800, 600, "First Window");
	app.img.res = mlx_new_image(app.mlx, 800, 600);

	/*
	** After creating an image, we can call `mlx_get_data_addr`, we pass
	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	** then be set accordingly for the *current* data address.
	*/
	app.img.addr = mlx_get_data_addr(app.img.res, &app.img.bits_per_pixel,
			&app.img.line_length, &app.img.endian);
	height_x_length(&app,5, 10);
	mlx_put_image_to_window(app.mlx, app.win, app.img.res, 0, 0);

	// loop the window so that it stays open and looks for user input
	mlx_loop(app.mlx);


}
