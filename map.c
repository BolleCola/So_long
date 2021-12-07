#include "so_long.h"

static void	error_map_two(char *mem)
{
	int	c;

	c = 0;
	if (chara('C', mem, 0) == 0)
		error();
	if (chara('E', mem, 0) == 0)
		error();
	if (chara('P', mem, 0) == 0)
		error();
	if (h_map(mem) >= l_map(mem))
		error();
	while (c < ft_strlen(mem))
	{
		if (l_map(&mem[0]) != l_map(&mem[c]))
			error();
		c += (l_map(mem) + 1);
	}
	c = 0;
	while (mem[c])
	{
		if (mem[c] != '1' && mem[c] != 'C' && mem[c] != '0' && mem[c] != 'E' 
			&& mem[c] != 'P' && mem[c] != '\n' && mem[c] != '\0')
			error();
		c++;
	}
}

static void	error_map(t_vars *vars, char *mem, int x, int c)
{
	int	i;
	int	j;

	i = 0;
	j = (ft_strlen(vars->map.mapnb) - 1);
	while (i <= l_map(mem))
	{
		if (vars->map.mapnb[i] != '1' || vars->map.mapnb[j] != '1')
			error();
		i++;
		j--;
	}
	i--;
	while (i < (ft_strlen(vars->map.mapnb) - (l_map(mem))))
	{
		if (vars->map.mapnb[i + (l_map(mem) - 1)] == '1' && vars->map.mapnb[i + l_map(mem)] == '1')
			i += l_map(mem);
		else
			error();
	}
	error_map_two(mem);
}

static void create_nb(t_vars *vars, char *mem)
{
	char 	*memnb;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (mem[i])
	{
		if (mem[i] == '\n')
			j++;
		i++;
	}
	memnb = ft_calloc_two(ft_strlen(mem) - (j - 1), 1);
	i = 0;
	j = 0;
	while (mem[i])
	{
		if (mem[i] == '\n')
			i++;
		memnb[j++] = mem[i++];
	}
	memnb[j] = '\0';
	vars->map.mapnb = memnb;
}

static void	create_win(t_vars *vars, char *mem)
{
	int		i;
	
	i = 0;
	vars->wind.h = 0;
	vars->wind.l = 0;
	while (mem[i] != '\n')
	{
		vars->wind.l+=16;
		i++;
	}
	i = 0;
	while (mem[i])
	{
		if (mem[i] == '\n')
			vars->wind.h+=16;
		i++;
	}
	vars->wind.h+=16;
}

void	generate_map(t_vars *vars)
{
    int     fd;
    char    *buff;
	char	*mem;

	mem = ft_strdup("");
	buff = ft_strdup("");
	fd = open("map.ber", O_RDONLY);
	while (buff != NULL)
	{		
		buff = get_next_line(fd);
		if (buff != NULL)
			mem = ft_strjoin(mem, buff);
		free(buff);
	}
	close(fd);
	create_nb(&*vars, mem);
	create_win(&*vars, mem);
	error_map(&*vars, mem, 0, 0);
	vars->map.mapb = mem;
	vars->map.h_map = h_map(mem);
	vars->map.l_map = l_map(mem);
}