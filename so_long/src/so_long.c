/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 00:59:25 by mtripodi          #+#    #+#             */
/*   Updated: 2025/01/23 12:18:23 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_loop(t_data *app)
{
	mlx_hook(app->win, DestroyNotify, 0, close_program, app);
	mlx_key_hook(app->win, handle_keyboard, app);
	//mlx_mouse_hook(app->win, handle_mouse, app);

	mlx_loop(app->mlx);
}

t_data	*ft_init(void)
{
	t_data		*app;

	app = malloc(sizeof(t_data));
	if (!app)
		return (NULL);
	app->map = malloc(sizeof(t_map));
	if (!app->map)
		return (NULL);
	app->tile_size = 64;
	app->map->txt = NULL;
	app->map->width = 0;
	app->map->height = 0;
	app->map->duck.x = 0;
	app->map->duck.y = 0;
	app->map->duck.collected = 0;
	app->map->collect = 0;
	app->map->exits = 0;
	app->map->entry = 0;
	app->map->moves = 0;
	return (app);
}

int	main(int arc, char *arv[])
{
	t_data		*app;
	void		*img;

	if (arc != 2)
		ft_err("No map has been selected", app, 2);
	app = ft_init();
	if (app == NULL)
		ft_err("Error initialising map", app, 1);
	app->map = prepare_map(app, arv[1]);
	init_window(app);
	ft_loop(app);
}
