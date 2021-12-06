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

int chara(char let, char *mem)
{
    int i;

    i = 0;
    while (mem[i])
	{
		if (mem[i] == let)
			return (1);
		i++;
	}
    return (0);
}