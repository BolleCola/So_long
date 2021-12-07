#include "so_long.h"

void	cal_i(t_vars *vars)
{
	int	j;
	int	c;

	c = 0;
	j = 0;
	while (vars->map.mapb[j])
	{
		if (vars->map.mapb[j] == '\n')
			c++;
		if (vars->map.mapb[j] == 'P')
			vars->perso.i = (j - c);
		j++;
	}

}

void    front(t_vars *vars)
{
    int larg;
    int haut;

	larg = 16;
	haut = 16;
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path.persob, &haut, &larg);
	if (vars->map.mapnb[vars->perso.i - l_map(vars->map.mapb)] != '1')
	{
		vars->perso.i -= l_map(vars->map.mapb);
		larg = vars->perso.x;
		haut = vars->perso.y;
		vars->perso.y -= 16;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->perso.x, vars->perso.y);
		put_grass(&*vars, larg, haut);
	}
}

void    back(t_vars *vars)
{
    int larg;
    int haut;

	larg = 16;
	haut = 16;
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path.persof, &haut, &larg);
	if (vars->map.mapnb[vars->perso.i + l_map(vars->map.mapb)] != '1')
	{
		vars->perso.i += l_map(vars->map.mapb);
		larg = vars->perso.x;
		haut = vars->perso.y;
		vars->perso.y += 16;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->perso.x, vars->perso.y);
		put_grass(&*vars, larg, haut);
	}
}

void    left(t_vars *vars)
{
    int larg;
    int haut;

	larg = 16;
	haut = 16;
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path.persor, &haut, &larg);
	if (vars->map.mapnb[vars->perso.i - 1] != '1')
	{
		vars->perso.i -= 1;
		larg = vars->perso.x;
		haut = vars->perso.y;
		vars->perso.x -= 16;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->perso.x, vars->perso.y);
		put_grass(&*vars, larg, haut);
	}
}

void    right(t_vars *vars)
{
    int larg;
    int haut;

	larg = 16;
	haut = 16;
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path.persol, &haut, &larg);
	if (vars->map.mapnb[vars->perso.i + 1] != '1')
	{
		vars->perso.i += 1;
		larg = vars->perso.x;
		haut = vars->perso.y;
		vars->perso.x += 16;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->perso.x, vars->perso.y);
		put_grass(&*vars, larg, haut);
	}
}