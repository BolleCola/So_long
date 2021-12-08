#include "so_long.h"

static void	pos_chest(t_vars *vars, char let, int i, int n)
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
		if (vars->map.mapb[i] == 'C' && y == n)
		{
			vars->chest.x = (g * 16);
			vars->chest.y = (j * 16);
			vars->chest.nb = vars->chest.nb + 1;
			break ;
		}
		g++;
		i++;
	}
}
void	put_chest(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
    vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path.chest, &vars->larg, &vars->haut);
	while (vars->map.mapnb[i])
	{
		if (vars->map.mapnb[i] == 'C')
		{
			pos_chest(&*vars, 'C', 0, j);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->chest.x, vars->chest.y);
			j++;
		}
		i++;
	}
}

void	chest_open(t_vars *vars)
{
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path.chesto, &vars->larg, &vars->haut);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img,  vars->perso.x, vars->perso.y);
	if (vars->map.mapnbm[vars->perso.i] == 'C')
		vars->chest.nb = vars->chest.nb - 1;
	vars->map.mapnbm[vars->perso.i] = '0';
	if (vars->chest.nb == 0)
		exit_open(&*vars);
}