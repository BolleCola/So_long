#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

# include "./mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
// gcc -Lmlx -lmlx -framework OpenGL -framework AppKit game.a

typedef struct s_map{
	char	*mapnb;
	char	*mapnbm;
	char	*mapb;
	int		h_map;
	int		l_map;
}	t_map;

typedef struct s_wind{
	int	h;
	int	l;
}	t_wind;

typedef struct s_path{
	char	*chest;
	char	*chesto;
	char	*exit;
	char	*h;
	char	*grass;
	char	*rock;
	char	*persof;
	char	*persob;
	char	*persol;
	char	*persor;
	char	*ennb;
	char	*ennf;
	char	*ennl;
	char	*ennr;
}	t_path;

typedef struct s_chest{
	int	x;
	int	y;
	int	nb;
}	t_chest;

typedef struct s_exit{
	int	x;
	int	y;
	int	o;
	int	i;
}	t_exit;

typedef struct s_perso{
	int	x;
	int	y;
	int	i;
	int	nb;
}	t_perso;

typedef struct s_enn{
	int		x;
	int		y;
	int		yon;
	int		inb;
	char	let;
}	t_enn;

typedef struct s_vars{
	void	*mlx;
	void	*win;
	void	*img;
	int		haut;
	int		larg;
	int		count;
	t_map	map;
	t_wind	wind;
	t_path	path;
	t_chest	chest;
	t_perso	perso;
	t_exit	exit;
	t_enn	enn;
}	t_vars;

void	generate_map(t_vars *vars);

void	*ft_calloc(size_t count, size_t size);

char	*ft_strjoin(char const *s1, char const *s2);

size_t	ft_strlen(const char *str);

char	*get_next_line(int fd);

char	*ft_strdup(const char *s1);

int		get_back_n(char *mem);

char	*get_strjoin(char *mem, char *buff);

char	*get_file_for_resul(int fd, int taille, char *mem, int n);

char	*get_resul(char *mem);

char	*get_newmem(char *mem, int j, int i);

int		l_map(char *mem);

int		h_map(char *mem);

void	snd_create_map(t_vars *vars, char *mem, char **mp);

void	*ft_calloc_two(size_t count, size_t size);

void	error(void);

int		chara(char let, char *mem, int i);

void	path(t_vars *vars);

void	set_image(t_vars *vars);

void	pos_perso(t_vars *vars, char let, int i, int n);

void	put_chest(t_vars *vars);

void	put_exit(t_vars *vars);

void	front(t_vars *vars);

void	back(t_vars *vars);

void	left(t_vars *vars);

void	right(t_vars *vars);

void	put_grass(t_vars *vars, int x, int y);

void	cal_i(t_vars *vars);

void	cal_p(t_vars *vars);

void	chest_open(t_vars *vars);

void	exit_open(t_vars *vars);

void	exit_prog(t_vars *vars);

void	put_enn(t_vars *v);

void	n_p(t_vars *v);

void	put_sign(t_vars *v, int x, int y);

void	move_enn(t_vars *v);

void	put_enn_two(t_vars *v);

void	put_chest_open(t_vars *v, int x, int y);

void	crash_enn(t_vars *v);

int		rallonge(t_vars *v, char lett);

int		rallonge_two(t_vars *v, char lett);

#endif