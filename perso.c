#include "so_long.h"

void	cal_i(t_vars *v)
{
	int	j;
	int	c;

	c = 0;
	j = 0;
	while (v->map.mapb[j])
	{
		if (v->map.mapb[j] == '\n')
			c++;
		if (v->map.mapb[j] == 'P')
			v->perso.i = (j - c);
		j++;
	}
}

void	front(t_vars *v)
{
	int	larg;
	int	haut;

	if (v->map.mapnb[v->perso.i - l_map(v->map.mapb)] != '1')
	{
		v->perso.i -= l_map(v->map.mapb);
		larg = v->perso.x;
		haut = v->perso.y;
		v->perso.y -= 16;
		if (v->map.mapnbm[v->perso.i] == 'C')
			chest_open(&*v);
		v->img = mlx_xpm_file_to_image(v->mlx, v->path.persob, &v->haut,
				&v->larg);
		mlx_put_image_to_window(v->mlx, v->win, v->img, v->perso.x,
			v->perso.y);
		put_grass(&*v, larg, haut);
		if (v->map.mapnbm[v->perso.i] == 'E' && v->exit.o == 1)
			exit_prog(&*v);
		if (v->map.mapnb[v->perso.i + l_map(v->map.mapb)] == 'E')
			put_sign(&*v, larg, haut);
		if (v->perso.i == v->enn.inb)
			crash_enn(&*v);
		if (v->map.mapnbm[v->perso.i + l_map(v->map.mapb)] == '5')
			put_chest_open(&*v, larg, haut);
	}
}

void	back(t_vars *v)
{
	int	larg;
	int	haut;

	if (v->map.mapnb[v->perso.i + l_map(v->map.mapb)] != '1')
	{
		v->perso.i += l_map(v->map.mapb);
		larg = v->perso.x;
		haut = v->perso.y;
		v->perso.y += 16;
		if (v->map.mapnbm[v->perso.i] == 'C')
			chest_open(&*v);
		v->img = mlx_xpm_file_to_image(v->mlx, v->path.persof, &v->haut,
				&v->larg);
		mlx_put_image_to_window(v->mlx, v->win, v->img, v->perso.x,
			v->perso.y);
		put_grass(&*v, larg, haut);
		if (v->map.mapnb[v->perso.i] == 'E' && v->exit.o == 1)
			exit_prog(&*v);
		if (v->map.mapnb[v->perso.i - l_map(v->map.mapb)] == 'E')
			put_sign(&*v, larg, haut);
		if (v->perso.i == v->enn.inb)
			crash_enn(&*v);
		if (v->map.mapnbm[v->perso.i - l_map(v->map.mapb)] == '5')
			put_chest_open(&*v, larg, haut);
	}
}

void	left(t_vars *v)
{
	int	larg;
	int	haut;

	if (v->map.mapnb[v->perso.i - 1] != '1')
	{
		v->perso.i -= 1;
		larg = v->perso.x;
		haut = v->perso.y;
		v->perso.x -= 16;
		if (v->map.mapnbm[v->perso.i] == 'C')
			chest_open(&*v);
		v->img = mlx_xpm_file_to_image(v->mlx, v->path.persor, &v->haut,
				&v->larg);
		mlx_put_image_to_window(v->mlx, v->win, v->img, v->perso.x,
			v->perso.y);
		put_grass(&*v, larg, haut);
		if (v->map.mapnb[v->perso.i] == 'E' && v->exit.o == 1)
			exit_prog(&*v);
		if (v->map.mapnb[v->perso.i + 1] == 'E')
			put_sign(&*v, larg, haut);
		if (v->perso.i == v->enn.inb)
			crash_enn(&*v);
		if (v->map.mapnbm[v->perso.i + 1] == '5')
			put_chest_open(&*v, larg, haut);
	}
}

void	right(t_vars *v)
{
	int	larg;
	int	haut;

	if (v->map.mapnb[v->perso.i + 1] != '1')
	{
		v->perso.i += 1;
		larg = v->perso.x;
		haut = v->perso.y;
		v->perso.x += 16;
		if (v->map.mapnbm[v->perso.i] == 'C')
			chest_open(&*v);
		v->img = mlx_xpm_file_to_image(v->mlx, v->path.persol, &v->haut,
				&v->larg);
		mlx_put_image_to_window(v->mlx, v->win, v->img, v->perso.x,
			v->perso.y);
		put_grass(&*v, larg, haut);
		if (v->map.mapnb[v->perso.i] == 'E' && v->exit.o == 1)
			exit_prog(&*v);
		if (v->map.mapnb[v->perso.i - 1] == 'E')
			put_sign(&*v, larg, haut);
		if (v->perso.i == v->enn.inb)
			crash_enn(&*v);
		if (v->map.mapnbm[v->perso.i - 1] == '5')
			put_chest_open(&*v, larg, haut);
	}
}
