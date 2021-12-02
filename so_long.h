#ifndef SO_LONG_H
# define SO_LONG_H

#include "./mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// gcc -Lmlx -lmlx -framework OpenGL -framework AppKit game.a

typedef struct s_data {
    void 	*img;
    char 	*addr;
}    t_data;

typedef struct s_vars{
    void *mlx;
    void *win;
}   t_vars;

#endif