/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_pix_put.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-15 23:05:01 by mtripodi          #+#    #+#             */
/*   Updated: 2025-01-15 23:05:01 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


void	ft_mlx_pix_put(t_image *data, int x, int y, int colour)
{
	char *dest;

	dest = data->addr + (y * data->line_length + x * (data->bits_per_pixel
		/ 8));
	*(unsigned int*)dest = colour;
}
