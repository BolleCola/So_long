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
