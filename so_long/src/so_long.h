/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 02:17:11 by mtripodi          #+#    #+#             */
/*   Updated: 2025/01/28 16:46:08 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h> //free, maloc
# include <unistd.h> //write, read, open
# include <fcntl.h> //open
# include <math.h>
# include <X11/keysym.h> //keysim codes XK_Escape
# include <X11/Xlib.h> // Button 1, button2 etc.
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

# define GRASS '0'
# define TREE '1'
# define COLL 'C'
# define EXIT 'E'
# define DUCK 'P'

/** I ended up using a bool as it made the code more readable, it also meant
 * if I wanted to change the return values, I could ctrl + f false/true and
 * it would only effect the bools, instead of other functions where I may
 * have used 0 or 1. */
typedef enum e_bool
{
	false,
	true
}			t_bool;

typedef struct s_flood
{
	int		collected;
	int		exits;
}			t_flood;

typedef struct s_duck
{
	int		x;
	int		y;
	int		collected;
}			t_duck;

// map struct, .ber is the file extention name.
typedef struct s_map
{
	char	**ber;
	int		width;
	int		height;
	t_duck	duck;
	int		collect;
	int		exits;
	int		entry;
	int		moves;
}				t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*textures[6];
	int		tile_size;
	int		victory;
	t_map	*map;
}				t_data;

// functions in my src dir
// ---  --------------------
// so_long.c
void		ft_loop(t_data *app);
t_data		*ft_init(void);

// directions.c
int			move_up(t_data *app, t_map *map, t_duck *duck);
int			move_right(t_data *app, t_map *map, t_duck *duck);
int			move_down(t_data *app, t_map *map, t_duck *duck);
int			move_left(t_data *app, t_map *map, t_duck *duck);

// check_movement.c
char		check_tile(t_map *map, char **txt, t_duck duck);
t_bool		collision_free(t_data *app, t_map *map, t_duck duck);
t_bool		check_move(t_data *app, char c);

// check_map
void		check_map(t_data *app, t_map *map, char **ber);
t_bool		check_boarder(t_map *map, char **ber);

//move_chapracter
void		found_duck(t_map *map, int x, int y);
void		move_duck_exit(t_data *app, t_duck duck_next, t_duck duck_past);
void		move_duck_img(t_data *app, t_duck duck_next, t_duck duck_past);

// hook
int			close_program(t_data *app);
int			handle_keyboard(int keycode, t_data *app);
int			handle_mouse(int button, t_data *app);

//utils
int			ft_read(int fd, char **line);
void		ft_err(char *msg, t_data *app, int n);

//free
void		free_map(t_map *map);
void		free_textures(t_data *app);
void		free_mlx(t_data *app);
void		free_app(t_data *app);

//window
void		place_win(t_data *app, t_map *map);
void		init_window(t_data *app);
int			get_texture(char c);

// textures
void		render_textures(t_data *app);
int			determine_texture(char **map, int col, int row);

//parse
t_bool		valid_map_path(t_map *map, int row, int col,
				t_flood *flood);
t_map		*prepare_map(t_data *app, char *path);
char		**get_map(char *path);
void		get_map_info(t_map *map);

#endif
