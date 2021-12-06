#ifndef SO_LONG_H
# define SO_LONG_H


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 128
#endif

#include "./mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
// gcc -Lmlx -lmlx -framework OpenGL -framework AppKit game.a

typedef struct s_map{
    char *mapnb;
    char *mapb;
}   t_map;

typedef struct s_wind{
    int h;
    int l;
}   t_wind;

typedef struct s_vars{
    void *mlx;
    void *win;
    void *img;
    char *addr;
    t_map map;
    t_wind wind;
}   t_vars;

void    generate_map(t_vars *vars);

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

int	    l_map(char *mem);

int	    h_map(char *mem);

void    snd_create_map(t_vars *vars, char *mem, char **mp);

void	*ft_calloc_two(size_t count, size_t size);

void    error();

int chara(char let, char *mem);

#endif