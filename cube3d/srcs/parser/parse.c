/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 00:01:35 by mtripodi          #+#    #+#             */
/*   Updated: 2025/04/24 14:33:16y mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "parser.h"


int	ft_err(char *msg, t_txt *map)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	if (map->txt)
		ft_free_strs(map->txt);
	return (1);
}

/**
 * @brief prepare_map is used to run the map functions to create it. It
 * will return a map pointer.
 */
int	*prepare_map(char *path)
{
	t_txt		*map;

	map->txt = get_map(path);
	if (map->txt == NULL || map->txt[0] == NULL)
	{
		ft_err("Failed to read map, Check Specified map Path", map);
		return (1);
	}

	get_map_info(map);
	return (check_map_valid(map, map->txt));
}

/**
 * @brief the ft_read function is responsible for reading the .txt file which
 * is handed in as an argument when running the program. It puts the map in
 * the *line so that the text can be used outside of this function. It reads
 * the txt one byte a time.
*/
int	ft_read(int fd, char **line)
{
	int			bytes;
	char		c;
	char		*buffer;

	bytes = 0;
	if (fd < 0)
		return (-1);
	buffer = ft_calloc(1000, sizeof(char));
	if (!buffer)
		return (-1);
	while (read(fd, &c, 1) > 0 && c && bytes < 1000 - 1)
		buffer[bytes++] = c;
	buffer[bytes] = '\0';
	*line = buffer;
	return (bytes + 1);
}

/**
 * @brief the ft_get_map reads the map putting each line
 * into a double pointer. This is done so I can later go through the contents
 * of the map to check if its valid, then push to screen.
 *
 * @param path
 * @return char **
*/
char	**get_map(char *path)
{
	int			fd;
	int			i;
	char		*buf;
	char		**map_txt;

	buf = NULL;
	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		return (NULL);
	}
	if (ft_read(fd, &buf) == -1)
		return (free(buf), NULL);
	while (buf[i])
	{
		if (buf[i] == '\n' && buf[i + 1] == '\n')
			return (free(buf), NULL);
		i++;
	}
	map_txt = ft_split(buf, '\n');
	free(buf);
	return (map_txt);
}

/**
 * @breif the get_map_info gets all the information about the map.
 * Why: So I can fill the map varialbe's with data relevant to the map
 *
 * @param map
*/
void	get_map_info(t_txt *map)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	map->width = ft_strlen(map->txt[0]);
	while (map->txt[y])
	{
		while (map->txt[y][x])
		{
			if (map->txt[y][x] == 'E')
				map->entry++;
			x++;
		}
		x = 0;
		y++;
	}
	map->height = y;
}
