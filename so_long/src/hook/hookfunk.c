/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookfunk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-17 00:26:52 by mtripodi          #+#    #+#             */
/*   Updated: 2025-01-17 00:26:52 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	handle_input(int keycode, t_app *app)
{
	if (keycode == 53)
	{
		mlx_destroy_window(app->mlx, app->win);
		mlx_destroy_display(app->mlx);
		free(app->mlx);
		ft_putstr_fd("close ordered", 1);
		return (0);
	}
	ft_printf("keycode %d\n", keycode);
}
