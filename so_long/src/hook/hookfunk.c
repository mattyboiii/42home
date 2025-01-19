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

int	handle_keyboard(int keysim, t_data *app)
{
	if (keysim == XK_Escape)
	{
		ft_printf("Key %d (ESC) has been pressed\n\n", keysim);
		free_mlx(app);
	}
	else if (keysim == XK_w)
	{
		ft_putendl_fd("Up", 1);
		move_up(app);
	}
	else if (keysim == XK_d)
	{
		ft_putendl_fd("Right", 1);
		move_right(app);
	}
	else if (keysim == XK_s)
	{
		ft_putendl_fd("Down", 1);
		move_down(app);
	}
	else if (keysim == XK_a)
	{
		ft_putendl_fd("Left", 1);
		move_left(app);
	}
	ft_printf("keysim %d\n", keysim);
}

int	handle_mouse(int button, t_data *app)
{
	if (button == Button1)
	{
		ft_putendl_fd("Pressed Left Mouse", 1);
	}
}
