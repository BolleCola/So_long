#include "so_long.h"

static void esc(t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
	exit_prog(&*vars);
}

static int    keyhook(int keycode, t_vars *vars)
{
    if (keycode == 53)
        esc(&*vars);
    if (keycode == 13)
        front(&*vars);
    if (keycode == 1)
        back(&*vars);
    if (keycode == 0)
        left(&*vars);
    if (keycode == 2)
        right(&*vars);
    return (0);
}

int main ()
{
    t_vars  vars;

    generate_map(&vars);
    path(&vars);
    cal_i(&vars);
	vars.haut = 16;
	vars.larg = 16;
	vars.chest.nb = 0;
    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, (vars.map.l_map * 16), (vars.map.h_map * 16), "Bolle's Dungeon !!!");
    set_image(&vars);
    mlx_key_hook(vars.win, keyhook, &vars);
    mlx_loop(vars.mlx);
}