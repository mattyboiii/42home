/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:29:34 by gcrisp            #+#    #+#             */
/*   Updated: 2025/04/24 15:49:28 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "map.h"

t_map	*parse(char *path)
{
	t_map	*map;
	t_txt	*txt;
	char	*first_bounds_line;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	map = new_map();
	first_bounds_line = parse_render_data(map, fd);
	if (!first_bounds_line)
	{
		close(fd);
		return (0);
	}
	txt = new_map_txt();
	if (!prepare_map_txt(txt, first_bounds_line, fd))
	{
		free_map(map);
		return (0);
	}
	return (map);
}
