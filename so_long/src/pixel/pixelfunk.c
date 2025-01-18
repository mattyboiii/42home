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

void draw_circle(t_data *app, int radius, int color)
{
	int i;
	int j;
	int dist;

	i = app->y - radius;
    while (i <= app->y + radius) {
        j = app->x - radius;
        while (j <= app->x + radius) {
            dist = (i - app->y) * (i - app->y) + (j - app->x) * (j - app->x);
            if (dist <= radius * radius) {
                ft_mlx_pix_put(app, j, i, color);
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

void	ft_mlx_pix_put(t_data *app, int x, int y, int colour)
{
	char *dest;

	dest = app->addr + (y * app->line_length + x * (app->bits_per_pixel
				/ 8));
	*(unsigned int*)dest = colour;
}
