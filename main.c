#include "so_long.h"

static void	esc(t_vars *v)
{
	mlx_destroy_window(v->mlx, v->win);
	exit_prog(&*v);
}

static int	keyhook(int keycode, t_vars *v)
{
	if (keycode == 53)
		esc(&*v);
	if (keycode == 13)
	{
		front(&*v);
		move_enn(&*v)
	}
	if (keycode == 1)
	{
		back(&*v);
		move_enn(&*v)
	}
	if (keycode == 0)	
	{
		left(&*v);
		move_enn(&*v)
	}
	if (keycode == 2)	
	{
		right(&*v);
		move_enn(&*v)
	}
	return (0);
}

int	main(void)
{
	t_vars	v;

	generate_map(&v);
	path(&v);
	cal_i(&v);
	v.enn.yon = 0;
	v.haut = 16;
	v.larg = 16;
	v.chest.nb = 0;
	v.mlx = mlx_init();
	v.win = mlx_new_window(v.mlx, (v.map.l_map * 16),
			(v.map.h_map * 16), "Bolle's Dungeon !!!");
	set_image(&v);
	mlx_key_hook(v.win, keyhook, &v);
	put_enn(&v);
	mlx_loop(v.mlx);
}
