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

static void	error_map(t_vars *v, char *mem, int x, int c)
{
	int	i;
	int	j;

	i = 0;
	j = (ft_strlen(v->map.mapnb) - 1);
	while (i <= l_map(mem))
	{
		if (v->map.mapnb[i] != '1' || v->map.mapnb[j] != '1')
			error();
		i++;
		j--;
	}
	i--;
	while (i < (ft_strlen(v->map.mapnb) - (l_map(mem))))
	{
		if (v->map.mapnb[i + (l_map(mem) - 1)] == '1' && v->map.mapnb[i
				+ l_map(mem)] == '1')
			i += l_map(mem);
		else
			error();
	}
	error_map_two(mem);
}

static void	create_nb(t_vars *v, char *mem)
{
	char	*memnb;
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
	v->map.mapnb = ft_strdup(memnb);
	v->map.mapnbm = ft_strdup(memnb);
	free(memnb);
}

static void	create_win(t_vars *v, char *mem)
{
	int		i;

	i = 0;
	v->wind.h = 0;
	v->wind.l = 0;
	while (mem[i] != '\n')
	{
		v->wind.l += 16;
		i++;
	}
	i = 0;
	while (mem[i])
	{
		if (mem[i] == '\n')
			v->wind.h += 16;
		i++;
	}
	v->wind.h += 16;
}

void	generate_map(t_vars *v)
{
	int		fd;
	char	*buff;
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
	create_nb(&*v, mem);
	create_win(&*v, mem);
	error_map(&*v, mem, 0, 0);
	v->map.mapb = ft_strdup(mem);
	v->map.h_map = h_map(mem);
	v->map.l_map = l_map(mem);
	free(mem);
}
