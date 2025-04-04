/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookfunk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 00:26:52 by mtripodi          #+#    #+#             */
/*   Updated: 2025/01/28 15:05:13 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
  * @brief handle keyboard function is used inside the main ft_loop, to track
  * which keys have been pressed by the user. Each if function checks if the
  * move is possible. This is used so the player can controll the duck.
  */
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
		&& check_move(app, 'd') == true)
		move_right(app, app->map, &app->map->duck);
	return (0);
}
