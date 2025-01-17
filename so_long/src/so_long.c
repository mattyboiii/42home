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
		int		spot;
		int		colour;
		int		x = 5;
		int		y = 5;

		colour = 0xFFFF0000;
		spot = 0;
		while (spot <= height)
		{
			ft_mlx_pix_put(&app->img, x, y + spot, colour);
			ft_mlx_pix_put(&app->img, x + length, y + spot, colour);
			spot++;
		}
		spot = 1;
		while (spot < length)
		{
			ft_mlx_pix_put(&app->img, x + spot, y, colour);
			ft_mlx_pix_put(&app->img, x + spot, y + height, colour);
			spot++;
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
	height_x_length(&app,100, 200);
	mlx_put_image_to_window(app.mlx, app.win, app.img.res, 0, 0);
	mlx_key_hook(app.win, handle_input, &app);

	// loop the window so that it stays open and looks for user input

	return (0);
}
