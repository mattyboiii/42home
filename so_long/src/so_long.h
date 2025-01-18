/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtripodi <mtripodi@student.42adel.o>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-15 02:17:11 by mtripodi          #+#    #+#             */
/*   Updated: 2025-01-15 02:17:11 by mtripodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h> //free, maloc
# include <unistd.h> //write
# include <math.h>
# include <X11/keysym.h> //keysim codes XK_Escape
# include <X11/Xlib.h> // Button 1, button2 etc.
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"


# ifndef ASS_PATH
#	define ASS_PATH = "./assets"
# endif

# ifndef TILE_SIZE
#  define TILE_SIZE 64
# endif

# ifndef HEIGHT
#  define HEIGHT 600
# endif

# ifndef WIDTH
#  define WIDTH 800
# endif

typedef unsigned char	byte;

typedef struct  s_data
{
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    int     radius;
    int     x;
    int     y;
}               t_data;

// functions in my src dir
// ---  --------------------

// so_long.c
int	ft_rgb(byte red, byte green, byte blue);

// character
int		move_up(t_data *app);
int		move_right(t_data *app);
int		move_down(t_data *app);
int		move_left(t_data *app);

// pixel
void	draw_circle(t_data *app, int radius, int color);
void	height_x_width(t_data *app, int height, int width);
void	ft_mlx_pix_put(t_data *app, int x, int y, int colour);

// hook
int	close_program(t_data *app);
int	handle_keyboard(int keycode, t_data *app);
int	handle_mouse(int button, t_data *app);

#endif
