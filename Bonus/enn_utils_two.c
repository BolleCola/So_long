/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enn_utils_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaquier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:17:04 by tpaquier          #+#    #+#             */
/*   Updated: 2021/12/17 14:17:06 by tpaquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	rallonge_two(t_vars *v, char lett)
{
	if (lett == 'd')
	{
		if (v->map.mapnb[v->enn.inb + l_map(v->map.mapb)] == '0')
			return (1);
		else
			v->enn.let = 'r';
	}
	return (0);
}
