/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookfunk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 00:26:52 by mtripodi          #+#    #+#             */
/*   Updated: 2025/01/20 14:58:40 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	handle_keyboard(int keysim, t_data *app)
{
	if (keysim == XK_Escape)
		close_program(app);
	else if (keysim == XK_w || keysim == XK_Up)
		check_move('w');
	else if (keysim == XK_d || keysim == XK_Down)
		check_move('d');
	else if (keysim == XK_s || keysim == XK_Right)
		check_move('s');
	else if (keysim == XK_a || keysim == XK_Left)
		check_move('a');
	ft_printf("keysim %d\n", keysim);
}

void handle_mouse(int button, t_data *app)
{
	if (button == Button1)
	{
		ft_putendl_fd("Pressed Left Mouse", 1);
	}
}
