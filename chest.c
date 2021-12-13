#include "so_long.h"

static void	pos_chest(t_vars *v, char let, int i, int n)
{
	int	g;
	int	j;
	int	y;

	j = 0;
	y = -1;
	g = 0;
	while (v->map.mapb[i])
	{
		if (g >= (l_map(v->map.mapb) + 1))
		{
			g = 0;
			j++;
		}
		if (v->map.mapb[i] == let)
			y++;
		if (v->map.mapb[i++] == 'C' && y == n)
		{
			v->chest.x = (g * 16);
			v->chest.y = (j * 16);
			v->chest.nb = v->chest.nb + 1;
			break ;
		}
		g++;
	}
}

void	put_chest(t_vars *v)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	v->img = mlx_xpm_file_to_image(v->mlx, v->path.chest, &v->larg, &v->haut);
	while (v->map.mapnb[i])
	{
		if (v->map.mapnb[i] == 'C')
		{
			pos_chest(&*v, 'C', 0, j);
			mlx_put_image_to_window(v->mlx, v->win, v->img,
				v->chest.x, v->chest.y);
			j++;
		}
		i++;
	}
}

void	chest_open(t_vars *v)
{
	v->img = mlx_xpm_file_to_image(v->mlx, v->path.chesto, &v->larg, &v->haut);
	mlx_put_image_to_window(v->mlx, v->win, v->img, v->perso.x, v->perso.y);
	if (v->map.mapnbm[v->perso.i] == 'C')
		v->chest.nb = v->chest.nb - 1;
	v->map.mapnbm[v->perso.i] = '0';
	if (v->chest.nb == 0)
		exit_open(&*v);
}
