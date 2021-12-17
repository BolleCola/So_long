/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaquier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:17:27 by tpaquier          #+#    #+#             */
/*   Updated: 2021/12/17 14:17:29 by tpaquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_sign(t_vars *v, int x, int y)
{
	v->img = mlx_xpm_file_to_image(v->mlx, v->path.exit, &v->larg, &v->haut);
	mlx_put_image_to_window(v->mlx, v->win, v->img, x, y);
}

static void	pos_exit(t_vars *v, char let, int i, int n)
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
		if (v->map.mapb[i++] == let && y == n)
		{
			v->exit.x = (g * 16);
			v->exit.y = (j * 16);
			break ;
		}
		g++;
	}
}

void	put_exit(t_vars *v)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	v->exit.o = 0;
	v->img = mlx_xpm_file_to_image(v->mlx, v->path.exit, &v->larg, &v->haut);
	while (v->map.mapnb[i])
	{
		if (v->map.mapnb[i] == 'E')
		{
			pos_exit(&*v, 'E', 0, j);
			mlx_put_image_to_window(v->mlx, v->win, v->img,
				v->exit.x, v->exit.y);
			v->exit.i = i;
			j++;
		}
		i++;
	}
}

void	exit_open(t_vars *v)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (v->map.mapnb[i])
	{
		if (v->map.mapnb[i] == 'E')
		{
			pos_exit(&*v, 'E', 0, j);
			v->img = mlx_xpm_file_to_image(v->mlx, v->path.grass, &v->larg,
					&v->haut);
			mlx_put_image_to_window(v->mlx, v->win, v->img, v->exit.x,
				v->exit.y);
			v->img = mlx_xpm_file_to_image(v->mlx, v->path.h, &v->larg,
					&v->haut);
			mlx_put_image_to_window(v->mlx, v->win, v->img, v->exit.x,
				v->exit.y);
			j++;
		}
		i++;
	}
	v->exit.o = 1;
}

int	exit_prog(t_vars *v)
{
	mlx_destroy_window(v->mlx, v->win);
	mlx_destroy_image(v->mlx, v->img);
	free(v->map.mapb);
	v->map.mapb = NULL;
	free(v->map.mapnb);
	v->map.mapnb = NULL;
	free(v->map.mapnbm);
	v->map.mapnbm = NULL;
	exit (1);
	return (0);
}
