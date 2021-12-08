#include "so_long.h"

static void	grass(t_vars *vars, int i, int g)
{
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path.grass, &vars->larg, &vars->haut);
	while (g < (vars->map.h_map * 16))
	{
		i = 0;
        while (i < (vars->map.l_map * 16))
        {
            mlx_put_image_to_window(vars->mlx, vars->win, vars->img, i, g);
            i+=16;
        }
		g+=16;
	}
}

static void	rock(t_vars *vars, int i, int j, int g)
{
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path.rock, &vars->larg, &vars->haut);
	while (vars->map.mapb[g])
	{
		if (vars->map.mapb[g] == '1')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, j, i);
		j += 16;
		if (vars->map.mapb[g] == '\n')
		{
			i += 16;
			j = 0;
		}
		g++;
	}
}

static void	perso(t_vars *vars)
{
	pos_perso(&*vars, 'P', 0, 0);
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path.persof, &vars->larg, &vars->haut);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->perso.x, vars->perso.y);
}

void	put_grass(t_vars *vars, int x, int y)
{
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path.grass, &vars->larg, &vars->haut);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x, y);
}

void    set_image(t_vars *vars)
{
	grass(&*vars, 0, 0);
	rock(&*vars, 0, 0, 0);
	perso(&*vars);
	put_chest(&*vars);
	put_exit(&*vars);
}