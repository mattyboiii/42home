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

/* encode RGB from numbrs to hexidecimal number value */
int	ft_rgb(byte red, byte green, byte blue)
{
	return (red << 16 | green << 8 | blue);
}


int		render_next_frame(void *app)
{
		display_score(app);
		render_bg(app);
		render_assets(app);
		return (0);
}
/*	The two lines of code below are essentially the same, one is just used
	to make code more concise

	mlx_hook(app->win, 2, 1L<<0, handle_input, &app->;
	mlx_key_hook(app->win, handle_input, &app->;
*/
void	ft_so_long(t_data *app)
{
	//create a structure which holds all the ptr's available to use and run
	// MiniLibx
	app->mlx = mlx_init();
	if (app->mlx == NULL)
		return (1);

	app->win = mlx_new_window (app->mlx, WIDTH, HEIGHT, "DUCK's Sake!!");
	//app->img = mlx_new_image(app->mlx, 800, 600);
	/*
	** After creating an image, we can call `mlx_get_data_addr`, we pass
	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	** then be set accordingly for the *current* data address.
	*/
	app->addr = mlx_get_data_addr(app->img, &app->bits_per_pixel,
			&app->line_length, &app->endian);
	//height_x_width(&app->100, 200);
	//draw_circle(&app-> 66, 0xFFFF0000);
	mlx_put_image_to_window(app->mlx, app->win, app->img, 0, 0);

	mlx_hook(app->win, DestroyNotify, 0, close_program, &app->;
	mlx_key_hook(app->win, handle_keyboard, &app->;
	mlx_mouse_hook(app->win, handle_mouse, &app->;

	// loop the window so that it stays open and looks for user input
	mlx_loop(app->mlx);

	return (0);
}
