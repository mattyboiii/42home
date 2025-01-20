/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 02:17:11 by mtripodi          #+#    #+#             */
/*   Updated: 2025/01/20 14:15:07 by mtripodi         ###   ########.fr       */
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

#	define TILE_SIZE 64

#	define GRASS '0'
#	define TREE '1'
#	define COLL 'C'
#	define EXIT 'E'
#	define DUCK 'P'

/** I ended up using a bool as it made the code more readable, it also meant
 * if I wanted to change the return values, I could ctrl + f false/true and
 * it would only effect the bools, instead of other functions where I may
 * have used 0 or 1. */
typedef enum e_bool
{
	false,
	true
}			t_bool;

typedef struct s_duck
{
	int		x;
	int		y;
}			t_duck;

typedef struct s_map
{
	char	**txt;
	int		width;
	int		height;
	t_duck	duck;
	int		collect;
	int		exits;
	int		entry;
	int		moves;
}				t_map;

typedef struct  s_data
{
    void    *mlx;
    void    *win;
	void	*textures[5];
	t_map	*map;

}               t_data;

// functions in my src dir
// ---  --------------------

// so_long.c

// character
int		move_up(t_data *app);
int		move_right(t_data *app);
int		move_down(t_data *app);
int		move_left(t_data *app);

// pixel

// hook
int	close_program(t_data *app);
int	handle_keyboard(int keycode, t_data *app);
int	handle_mouse(int button, t_data *app);

//utils
int	ft_read(int fd, char **line);
int		ft_exit(int n);
int		ft_err(char *msg, int n);

//free
void		free_app(t_data *app);
void		free_mlx(t_data *app);

//window
void		init_window(t_data *app);

//parse
char		**get_map(char *path);


#endif
