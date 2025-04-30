/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:23:35 by gcrisp            #+#    #+#             */
/*   Updated: 2025/04/24 15:49:54 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <fcntl.h>
# include "libft.h"
# include "map.h"
# include "mlx_util.h"

t_map	*parse(char	*path);

int		prepare_map_txt(t_txt *map, char *first_line, int fd);
int		check_map_valid(t_txt *map, char **txt);

char	*parse_render_data(t_map *map, int fd);
int		parse_bounds(t_map *map, char *line, int fd);

int		parse_map_line(t_map *map, char *line, char *prev_line,
			size_t line_num);

int		is_inside(char c);
int		is_outside(char c);
int		is_player(char c);
int		is_empty(char c);

#endif
