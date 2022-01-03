/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enn_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaquier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:17:13 by tpaquier          #+#    #+#             */
/*   Updated: 2021/12/17 14:17:15 by tpaquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	enn_r(t_vars *v)
{
	put_grass(&*v, v->enn.x, v->enn.y);
	v->img = mlx_xpm_file_to_image(v->mlx, v->path.ennl, &v->haut, &v->larg);
	mlx_put_image_to_window(v->mlx, v->win, v->img, (v->enn.x += 16),
		v->enn.y);
}

static void	enn_l(t_vars *v)
{
	put_grass(&*v, v->enn.x, v->enn.y);
	v->img = mlx_xpm_file_to_image(v->mlx, v->path.ennr, &v->haut, &v->larg);
	mlx_put_image_to_window(v->mlx, v->win, v->img, (v->enn.x -= 16),
		v->enn.y);
}

static void	enn_b(t_vars *v)
{
	put_grass(&*v, v->enn.x, v->enn.y);
	v->img = mlx_xpm_file_to_image(v->mlx, v->path.ennb, &v->haut, &v->larg);
	mlx_put_image_to_window(v->mlx, v->win, v->img, v->enn.x,
		(v->enn.y -= 16));
}

static void	enn_f(t_vars *v)
{
	put_grass(&*v, v->enn.x, v->enn.y);
	v->img = mlx_xpm_file_to_image(v->mlx, v->path.ennf, &v->haut, &v->larg);
	mlx_put_image_to_window(v->mlx, v->win, v->img, v->enn.x,
		(v->enn.y += 16));
}

void	move_enn(t_vars *v)
{
	if (v->enn.yon != 0)
	{
		if (v->enn.let == 'r')
		{
			if (v->map.mapnb[v->enn.inb + 1] == '0')
				enn_r(&*v);
			else
				v->enn.let = 'b';
		}
		if (v->enn.let == 'b')
		{
			if (v->map.mapnb[v->enn.inb - l_map(v->map.mapb)] == '0')
				enn_b(&*v);
			else
				v->enn.let = 'l';
		}
		if (rallonge(&*v, v->enn.let) == 1)
			enn_l(&*v);
		if (rallonge_two(&*v, v->enn.let) == 1)
			enn_f(&*v);
		put_enn_two(&*v);
		crash_enn(&*v);
	}
}
