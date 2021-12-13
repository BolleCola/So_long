#include "so_long.h"

void	put_enn(t_vars *v)
{
	v->enn.x = v->exit.x;
	v->enn.y = v->exit.y;
	v->img = mlx_xpm_file_to_image(v->mlx, v->path.ennf, &v->haut, &v->larg);
	if (v->map.mapnb[v->exit.i + 1] != '1')
		mlx_put_image_to_window(v->mlx, v->win, v->img, (v->enn.x + 16),
				v->enn.y);
	else if (v->map.mapnb[v->exit.i - 1] != '1')
		mlx_put_image_to_window(v->mlx, v->win, v->img, (v->enn.x - 16),
				v->enn.y);
	else if (v->map.mapnb[v->exit.i - l_map(v->map.mapb)] != '1')
		mlx_put_image_to_window(v->mlx, v->win, v->img, v->enn.x,
				(v->enn.y - 16));
	else if (v->map.mapnb[v->exit.i + l_map(v->map.mapb)] != '1')
		mlx_put_image_to_window(v->mlx, v->win, v->img, v->enn.x,
				(v->enn.y + 16));
}