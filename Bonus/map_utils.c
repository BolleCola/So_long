/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaquier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:18:20 by tpaquier          #+#    #+#             */
/*   Updated: 2021/12/17 14:18:22 by tpaquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	h_map(char *mem)
{
	int	i;
	int	resul;

	resul = 0;
	i = 0;
	while (mem[i])
	{
		if (mem[i] == '\n')
			resul++;
		i++;
	}
	return (++resul);
}

int	l_map(char *mem)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mem[i])
	{
		if (mem[i] == '\n')
			break ;
		i++;
		j++;
	}
	return (j);
}

void	error(char *mem, t_vars *v)
{
	printf("erreur de chargement de map\n");
	free(mem);
	free(v->map.mapb);
	free(v->map.mapnb);
	free(v->map.mapnbm);
	exit (1);
}

int	chara(char let, char *mem, int i)
{
	while (mem[i])
	{
		if (mem[i] == let)
			return (1);
		i++;
	}
	return (0);
}

void	pos_perso(t_vars *v, char let, int i, int n)
{
	int	g;
	int	j;

	j = 0;
	g = 0;
	n_p(&*v);
	while (v->map.mapb[i])
	{
		if (g >= (l_map(v->map.mapb) + 1))
		{
			g = 0;
			j++;
		}
		if (v->map.mapb[i] == let)
			n++;
		if (v->map.mapb[i] == let && n == v->perso.nb)
		{
			v->perso.x = (g * 16);
			v->perso.y = (j * 16);
			break ;
		}
		g++;
		i++;
	}
}
