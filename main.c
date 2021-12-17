/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaquier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:18:01 by tpaquier          #+#    #+#             */
/*   Updated: 2021/12/17 14:18:02 by tpaquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_exit(void)
{
	printf("Erreur, votre argument pour la map n'est pas correct !\n");
	exit (1);
}

static int	keyhook(int keycode, t_vars *v)
{
	if (keycode == 13 || keycode == 1 || keycode == 0 || keycode == 2)
	{
		v->count += 1;
		printf("%d\n", v->count);
	}
	if (keycode == 13 || keycode == 1 || keycode == 0 || keycode == 2)
		move_enn(&*v);
	if (keycode == 53)
		exit_prog(&*v);
	if (keycode == 13)
		front(&*v);
	if (keycode == 1)
		back(&*v);
	if (keycode == 0)
		left(&*v);
	if (keycode == 2)
		right(&*v);
	return (0);
}

void	error_ber(char *argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		if (argv[i] == '.')
			j = i;
		i++;
	}
	if (argv[j + 1] != 'b' || argv[j + 2] != 'e' || argv[j + 3] != 'r')
		map_exit();
}

int	main(int argc, char *argv[])
{
	t_vars	v;

	if (argc < 2)
		map_exit();
	generate_map(&v, argv[1]);
	path(&v);
	cal_i(&v);
	v.enn.yon = 0;
	v.haut = 16;
	v.larg = 16;
	v.chest.nb = 0;
	v.count = 0;
	v.mlx = mlx_init();
	v.win = mlx_new_window(v.mlx, (v.map.l_map * 16),
			(v.map.h_map * 16), "Bolle's Dungeon !!!");
	set_image(&v);
	mlx_key_hook(v.win, keyhook, &v);
	put_enn(&v);
	mlx_hook(v.win, 17, 1L << 0, exit_prog, &v);
	mlx_loop(v.mlx);
}
