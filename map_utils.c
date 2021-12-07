#include "so_long.h"

int	h_map(char *mem)
{
	int i;
	int resul;

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

void    error()
{
    printf("erreur de chargement de map\n");
    exit (1);
}

int chara(char let, char *mem, int i)
{
    while (mem[i])
	{
		if (mem[i] == let)
			return (1);
		i++;
	}
    return (0);
}

void	pos_perso(t_vars *vars, char let, int i, int n)
{
	int g;
	int j;
	
	j = 0;
	g = 0;
	while (vars->map.mapb[i])
	{
		if (g >= (l_map(vars->map.mapb) + 1))
		{
			g = 0;
			j++;
		}
		if (vars->map.mapb[i] == let)
		{
			vars->perso.x = (g * 16);
			vars->perso.y = (j * 16);
			break ;
		}
		g++;
		i++;
	}
}