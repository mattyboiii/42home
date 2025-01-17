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
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

typedef struct s_data
{
	void	*res;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

typedef struct s_app
{
	void		*mlx; //mlx_ptr
	void		*win; //win_ptr
	t_image		img;  //img struct
}				t_app;

// functions in my src dir
// ---  --------------------
// pixel
void	ft_mlx_pix_put(t_image *data, int x, int y, int colour);

// hook
int	handle_input(int keycode, t_app *app);

#endif
