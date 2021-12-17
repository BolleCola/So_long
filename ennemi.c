/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaquier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:17:20 by tpaquier          #+#    #+#             */
/*   Updated: 2021/12/17 14:17:22 by tpaquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_enn_two(t_vars *v)
{
	v->enn.inb = ((v->enn.y / 16) * l_map(v->map.mapb) + (v->enn.x / 16));
}

static void	yon(t_vars *v)
{
	if (v->map.mapnb[v->exit.i + 1] == '0')
		v->enn.yon = 1;
	else if (v->map.mapnb[v->exit.i - 1] == '0')
		v->enn.yon = 1;
	else if (v->map.mapnb[v->exit.i - l_map(v->map.mapb)] == '0')
		v->enn.yon = 1;
	else if (v->map.mapnb[v->exit.i + l_map(v->map.mapb)] == '0')
		v->enn.yon = 1;
}

void	put_enn(t_vars *v)
{
	v->enn.x = v->exit.x;
	v->enn.y = v->exit.y;
	v->img = mlx_xpm_file_to_image(v->mlx, v->path.ennf, &v->haut, &v->larg);
	if (v->map.mapnb[v->exit.i + 1] == '0')
		mlx_put_image_to_window(v->mlx, v->win, v->img, (v->enn.x += 16),
			v->enn.y);
	else if (v->map.mapnb[v->exit.i - 1] == '0')
		mlx_put_image_to_window(v->mlx, v->win, v->img, (v->enn.x -= 16),
			v->enn.y);
	else if (v->map.mapnb[v->exit.i - l_map(v->map.mapb)] == '0')
		mlx_put_image_to_window(v->mlx, v->win, v->img, v->enn.x,
			(v->enn.y -= 16));
	else if (v->map.mapnb[v->exit.i + l_map(v->map.mapb)] == '0')
		mlx_put_image_to_window(v->mlx, v->win, v->img, v->enn.x,
			(v->enn.y += 16));
	else
	{
		v->enn.x = 0;
		v->enn.y = 0;
	}
	v->enn.inb = 0;
	v->enn.let = 'r';
	put_enn_two(&*v);
	yon(&*v);
}

void	crash_enn(t_vars *v)
{
	if (v->enn.inb == v->perso.i)
	{
		printf("Oh ! no ... un skelette vous a tuer ... la honte !\n");
		exit_prog(&*v);
	}
}

int	rallonge(t_vars *v, char lett)
{
	if (lett == 'l')
	{
		if (v->map.mapnb[v->enn.inb - 1] == '0')
			return (1);
		else
			v->enn.let = 'd';
	}
	return (0);
}
