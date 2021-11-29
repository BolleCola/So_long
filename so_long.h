#ifndef SO_LONG_H
# define SO_LONG_H

#include "./mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
// gcc -Lmlx -lmlx -framework OpenGL -framework AppKit game.a

typedef struct s_data {
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
}   t_data;

typedef struct s_vars{
    void *mlx;
    void *win;
}   t_vars;

void    my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif