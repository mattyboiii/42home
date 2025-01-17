/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixelfunk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-15 23:05:01 by mtripodi          #+#    #+#             */
/*   Updated: 2025/01/17 16:32:51 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void draw_circle(t_data *img, int radius, int color) {
    int i = HEIGHT / 2 - radius;
    int j;
    int center_x = WIDTH / 2;
    int center_y = HEIGHT / 2;
    int distance;

    while (i <= center_y + radius) {
        j = center_x - radius;
        while (j <= center_x + radius) {
            distance = (i - center_y) * (i - center_y) + (j - center_x) * (j - center_x);
            if (distance <= radius * radius) {
                ft_mlx_pix_put(img, j, i, color);
            }
            j++;
        }
        i++;
    }
}

void	height_x_width(t_data *app, int height, int width)
{
	int		spot;
	int		colour;
	int		x = 5;
	int		y = 5;

	colour = 0xFFFF0000;
	spot = 0;
	while (spot <= height)
	{
		ft_mlx_pix_put(app, x, y + spot, colour);
		ft_mlx_pix_put(app, x + width, y + spot, colour);
		spot++;
	}
	spot = 1;
	while (spot < width)
	{
		ft_mlx_pix_put(app, x + spot, y, colour);
		ft_mlx_pix_put(app, x + spot, y + height, colour);
		spot++;
	}
}

void	ft_mlx_pix_put(t_data *data, int x, int y, int colour)
{
	char *dest;

	dest = data->addr + (y * data->line_length + x * (data->bits_per_pixel
				/ 8));
	*(unsigned int*)dest = colour;
}
