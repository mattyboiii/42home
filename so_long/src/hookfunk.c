/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookfunk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 00:26:52 by mtripodi          #+#    #+#             */
/*   Updated: 2025/01/23 12:09:33 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	handle_keyboard(int keysim, t_data *app)
{
	if (keysim == XK_Escape || app->victory == 1)
		close_program(app);
	else if ((keysim == XK_w || keysim == XK_Up)
			&& check_move(app, 'w') == true)
		move_up(app, app->map, &app->map->duck);
	else if ((keysim == XK_s || keysim == XK_Down)
			&& check_move(app, 's') == true)
		move_down(app, app->map, &app->map->duck);
	else if ((keysim == XK_a || keysim == XK_Left)
			&& check_move(app, 'a') == true)
		move_left(app, app->map, &app->map->duck);
	else if ((keysim == XK_d || keysim == XK_Right)
			&& check_move(app,'d') == true)
		move_right(app, app->map, &app->map->duck);
	return (0);
}

int	handle_mouse(int button, t_data *app)
{
	if (button == Button1)
	{
		ft_putendl_fd("Pressed Left Mouse", 1);
	}
	return (0);
}
