/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 23:19:15 by mtripodi          #+#    #+#             */
/*   Updated: 2025/01/23 14:33:01 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"


int	ft_read(int fd, char **line)
{
	int			bytes;
	char		c;
	char		*buffer;

	bytes = 0;
	if (fd < 0)
		return (-1);
	buffer = ft_calloc(100000, sizeof(char));
	if (!buffer)
		return (-1);
	while (read(fd, &c, 1) > 0 && c && bytes < 100000 - 1)
		buffer[bytes++] = c;
	buffer[bytes] = '\0';
	*line = buffer;
	return (bytes + 1);
}

/**
 * @breif the ft_err function is mainly responsible for printing function
 * dedicated errors to stderr during an error.
 *
 * It will also free the app assuming its passed in.
 *
 * It can also exit the program assuming that you have supplied a number > 0.
 *
 *
 * @param char *msg, t_data *app, int n
 * @return 0
*/
void	ft_err(char *msg, t_data *app, int n)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	if (app)
		free_app(app);
	if (n > 0)
		exit(n);
}

/**
 * @brief close_program. will simply run free_app, to clear all memory.
 * then it will exit(0); as to not include any errors on the exit.
 *
 */
int	close_program(t_data *app)
{
	free_app(app);
	if (app->victory == 1)
		ft_putendl_fd("Victory!!! Well Ducking Done :)", 1);
	else
		ft_putendl_fd("Close program Initiated\nClosing Program...", 1);
	exit(0);
	return (0);
}
