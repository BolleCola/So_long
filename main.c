#include "so_long.h"

int main ()
{
    t_vars  vars;

    generate_map(&vars);
	//vars.mlx = mlx_init();
    printf("h : %d\n", vars.wind.h);
    printf("l : %d\n", vars.wind.l);
    printf("mapb : %s\n", vars.map.mapb);
    printf("mapnb : %s\n", vars.map.mapnb);

   	//mlx_loop(vars.mlx);
}