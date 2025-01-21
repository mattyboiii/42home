#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    void    *mlx;
    void    *win;
    void    *img;
    int     img_width = 64;
    int     img_height = 64;

    // Initialize the MiniLibX
    mlx = mlx_init();
    if (!mlx)
    {
        perror("Failed to initialize MLX");
        exit(EXIT_FAILURE);
    }

    // Create a new window
    win = mlx_new_window(mlx, 800, 600, "Display XPM Image");
    if (!win)
    {
        perror("Failed to create a new window");
        exit(EXIT_FAILURE);
    }

    // Load the XPM file into an image
    img = mlx_xpm_file_to_image(mlx, "assets/grass.xpm", &img_width, &img_height);
    if (!img)
    {
        perror("Failed to load XPM file");
        exit(EXIT_FAILURE);
    }

    // Display the image in the window
    mlx_put_image_to_window(mlx, win, img, 0, 0);

    // Keep the window open
    mlx_loop(mlx);

    return 0;
}
