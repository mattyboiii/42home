/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:25:18 by gcrisp            #+#    #+#             */
/*   Updated: 2025/04/24 15:15:27 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "libft.h"
# include "casting.h"
# include "mlx_util.h"

// wall_paths is arranged NESW
typedef struct s_map
{
	t_point		player_start;
	float		start_dir;
	t_vector	*bounds;
	char		*wall_paths[4];
	int			ciel_colour;
	int			floor_colour;
}	t_map;

typedef struct s_maptext
{
	char	**txt;
	int		height;
	int		width;
	int		entry;
}	t_txt;

t_map		*new_map(void);
t_txt		*new_map_txt(void);
void		free_map(t_map *map);

#endif
