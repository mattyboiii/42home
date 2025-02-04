/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 00:59:25 by mtripodi          #+#    #+#             */
/*   Updated: 2025/02/04 10:37:43 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 */
void	ft_loop(t_data *app)
{
	mlx_hook(app->win, DestroyNotify, 0, close_program, app);
	mlx_key_hook(app->win, handle_keyboard, app);
	mlx_loop(app->mlx);
}

/**
 * @brief ft_init simply initialises the app. This is important to assign
 * values to all of the variables along with initialising them. Now variables
 * can be assigned.
 *
 * NATE thinks I could have used bzero here. So maybe think about this next
 * time :) Check below
 */

/*
t_data	*ft_nateinit(void)
{
	t_data	*app;

	app = malloc(sizeof(*app));
	bzero(app, sizeof(*app));
	app->map = malloc(sizeof(*app->map));
	bzero(app, sizeof(*app->map));
	app->tile_size = 64;
	return (app);
}
*/
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
	app->victory = 0;
	app->map->ber = NULL;
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

/**
 * main function, first point of the program
 *
 * if i was to do this again, I would make the t_data *app; a non pointer.
 *
 * t_data app; ---> this way the memory is stored in the stack, making ft_init free of having
 * to allocate memo
 */
int	main(int arc, char *arv[])
{
	t_data		*app;

	app = NULL;
	if (arc != 2)
		ft_err("No map has been selected", app, 2);
	app = ft_init();
	if (app == NULL)
		ft_err("Error initialising map", app, 1);
	app->map = prepare_map(app, arv[1]);
	init_window(app);
	ft_loop(app);
}
