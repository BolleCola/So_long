#include "so_long.h"

static void	ft_bzero(void *s, size_t n)
{
	char	*s2;

	s2 = (char *)s;
	while (n > 0)
	{
		*s2 = 0;
		s2++;
		n--;
	}
}

void	*ft_calloc_two(size_t count, size_t size)
{
	void	*mem;

	mem = malloc(count * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, count * size);
	return (mem);
}

size_t	ft_strlen(const char *str)
{
	size_t	resul;

	resul = 0;
	while (str[resul])
		resul++;
	return (resul);
}

void	path(t_vars *vars)
{
	vars->path.chest = "./pack/xpm/chest_c.xpm";
	vars->path.chesto = "./pack/xpm/chest_o.xpm";
	vars->path.exit = "./pack/xpm/Sign.xpm";
	vars->path.h = "./pack/xpm/Heart.xpm";
	vars->path.grass = "./pack/xpm/Grass.xpm";
	vars->path.rock = "./pack/xpm/Rock.xpm";
	vars->path.persof = "./pack/xpm/perso_f.xpm";
	vars->path.persob = "./pack/xpm/perso_b.xpm";
	vars->path.persol = "./pack/xpm/perso_d.xpm";
	vars->path.persor = "./pack/xpm/perso_g.xpm";
}