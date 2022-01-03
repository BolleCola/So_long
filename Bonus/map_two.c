/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_two.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaquier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:18:12 by tpaquier          #+#    #+#             */
/*   Updated: 2021/12/17 14:18:13 by tpaquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	grass(t_vars *v, int i, int g)
{
	v->img = mlx_xpm_file_to_image(v->mlx, v->path.grass, &v->larg, &v->haut);
	while (g < (v->map.h_map * 16))
	{
		i = 0;
		while (i < (v->map.l_map * 16))
		{
			mlx_put_image_to_window(v->mlx, v->win, v->img, i, g);
			i += 16;
		}
		g += 16;
	}
}

static void	rock(t_vars *v, int i, int j, int g)
{
	v->img = mlx_xpm_file_to_image(v->mlx, v->path.rock, &v->larg, &v->haut);
	while (v->map.mapb[g])
	{
		if (v->map.mapb[g] == '1')
			mlx_put_image_to_window(v->mlx, v->win, v->img, j, i);
		j += 16;
		if (v->map.mapb[g] == '\n')
		{
			i += 16;
			j = 0;
		}
		g++;
	}
}

static void	perso(t_vars *v)
{
	pos_perso(&*v, 'P', 0, 0);
	v->img = mlx_xpm_file_to_image(v->mlx, v->path.persof, &v->larg, &v->haut);
	mlx_put_image_to_window(v->mlx, v->win, v->img, v->perso.x, v->perso.y);
}

void	put_grass(t_vars *v, int x, int y)
{
	v->img = mlx_xpm_file_to_image(v->mlx, v->path.grass, &v->larg, &v->haut);
	mlx_put_image_to_window(v->mlx, v->win, v->img, x, y);
}

void	set_image(t_vars *v)
{
	grass(&*v, 0, 0);
	rock(&*v, 0, 0, 0);
	perso(&*v);
	put_chest(&*v);
	put_exit(&*v);
}
