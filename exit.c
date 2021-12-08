#include "so_long.h"

static void	pos_exit(t_vars *vars, char let, int i, int n)
{
	int g;
	int j;
	int	y;
	
	j = 0;
	y = -1;
	g = 0;
	while (vars->map.mapb[i])
	{
		if (g >= (l_map(vars->map.mapb) + 1))
		{
			g = 0;
			j++;
		}
		if (vars->map.mapb[i] == let)
			y++;
		if (vars->map.mapb[i] == let && y == n)
		{
			vars->exit.x = (g * 16);
			vars->exit.y = (j * 16);
			break ;
		}
		g++;
		i++;
	}
}

void	put_exit(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
  	vars->exit.o = 0;
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path.exit, &vars->larg, &vars->haut);
	while (vars->map.mapnb[i])
	{
		if (vars->map.mapnb[i] == 'E')
		{
			pos_exit(&*vars, 'E', 0, j);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->exit.x, vars->exit.y);
			j++;
		}
		i++;
	}
}

void	exit_open(t_vars *vars)
{
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path.grass, &vars->larg, &vars->haut);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->exit.x, vars->exit.y);
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path.h, &vars->larg, &vars->haut);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->exit.x, vars->exit.y);
	vars->exit.o = 1;
}

void	exit_prog(t_vars *vars)
{
	free(vars->map.mapb);
	vars->map.mapb = NULL;
	free(vars->map.mapnb);
	vars->map.mapnb = NULL;
	free(vars->map.mapnbm);
	vars->map.mapnbm = NULL;
	printf("\nBravo ! Vous avez gagne\n");
	exit (1);
}