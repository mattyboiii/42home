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

#include <stdio.h>
#include "so_long.h"
#include "minilibx-linux/mlx.h"


int	main(void)
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		img;

	//create a structure which holds all the ptr's available to use and run
	// MiniLibx
	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (1);

	// create my first window
	win_ptr = mlx_new_window (mlx_ptr, 800, 600, "First Window");
	img.img = mlx_new_image(mlx_ptr, 1920, 1080);

	/*
	** After creating an image, we can call `mlx_get_data_addr`, we pass
	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	** then be set accordingly for the *current* data address.
	*/
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
					img.endian);

	// loop the window so that it stays open and looks for user input
	mlx_loop(mlx_ptr);


}
