#include "so_long.h"

int close_test(int keycode, t_vars *vars)
{
	static int i = 32;
	static int j = 32;
	t_data	img2;
	int	hauteur = 16;
	int largeur = 16;
	char *pers = "./pack/xpm/perso_f.xpm";
	char *grass = "./pack/xpm/Grass.xpm";
	char *persb = "./pack/xpm/perso_b.xpm";
	char *persg = "./pack/xpm/perso_g.xpm";
	char *persd = "./pack/xpm/perso_d.xpm";
	if (i == 272)
		i-=16;
	if (i == 0)
		i+=16;
	if (j == 128)
		j-=16;
	if (j == 0)
		j+=16;
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit (1);
	}
	if (keycode == 1 && j < 128 && j > 16)
	{
		img2.img = mlx_xpm_file_to_image(vars->mlx, pers, &hauteur, &largeur);
		mlx_put_image_to_window(vars->mlx, vars->win, img2.img, i, j+=16);
		img2.img = mlx_xpm_file_to_image(vars->mlx, grass, &hauteur, &largeur);
		mlx_put_image_to_window(vars->mlx, vars->win, img2.img, i, j-16);
	}
	if (keycode == 13 && j < 128 && j > 16)
	{
		img2.img = mlx_xpm_file_to_image(vars->mlx, persb, &hauteur, &largeur);
		mlx_put_image_to_window(vars->mlx, vars->win, img2.img, i, j-=16);
		img2.img = mlx_xpm_file_to_image(vars->mlx, grass, &hauteur, &largeur);
		mlx_put_image_to_window(vars->mlx, vars->win, img2.img, i, j+16);
	}
	if (keycode == 2 && i < 288 && i > 16)
	{
		img2.img = mlx_xpm_file_to_image(vars->mlx, persd, &hauteur, &largeur);
		mlx_put_image_to_window(vars->mlx, vars->win, img2.img, i+=16, j);
		img2.img = mlx_xpm_file_to_image(vars->mlx, grass, &hauteur, &largeur);
		mlx_put_image_to_window(vars->mlx, vars->win, img2.img, i-16, j);
	}
	if (keycode == 0 && i < 288 && i > 16)
	{
		img2.img = mlx_xpm_file_to_image(vars->mlx, persg, &hauteur, &largeur);
		mlx_put_image_to_window(vars->mlx, vars->win, img2.img, i-=16, j);
		img2.img = mlx_xpm_file_to_image(vars->mlx, grass, &hauteur, &largeur);
		mlx_put_image_to_window(vars->mlx, vars->win, img2.img, i+16, j);
	}
	return (-1);
}

int main(void)
{
    t_vars vars;
	t_data img;
	char *grass = "./pack/xpm/Grass.xpm";
	char *rock = "./pack/xpm/Rock.xpm";
	char *chest = "./pack/xpm/chest_c.xpm";
	char *sign = "./pack/xpm/Sign.xpm";
	char *pers = "./pack/xpm/perso_f.xpm";
	int	hauteur = 16;
	int largeur = 16;
	int	i;
	int j;
	int x;
	x = -1;
	j = 0;
	i = 0;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Bolle's Dungeon");
	img.img = mlx_xpm_file_to_image(vars.mlx, grass, &hauteur, &largeur);
	while (i <= 480)
	{
		if (i >= 480 && j < 640)
		{
			j+=16;
			i = 0;
		}
		else
		{
			mlx_put_image_to_window(vars.mlx, vars.win, img.img, j, i);
			i+=16;
		}
	}
	img.img = mlx_xpm_file_to_image(vars.mlx, rock, &hauteur, &largeur);
	i = 0;
	j = 0;
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	while (i <= 160)
	{	
		mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, i+=16);
	}
	while (j <= 320)
	{
		mlx_put_image_to_window(vars.mlx, vars.win, img.img, j+=16, 0);
	}
	i = 0;
	while (i <= 160)
	{
		mlx_put_image_to_window(vars.mlx, vars.win, img.img, 304, i+=16);
	}
	j = 0;
	while (j <= 320)
	{
		mlx_put_image_to_window(vars.mlx, vars.win, img.img, j+=16, 144);
	}
	img.img = mlx_xpm_file_to_image(vars.mlx, chest, &hauteur, &largeur);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 32, 16);
	img.img = mlx_xpm_file_to_image(vars.mlx, sign, &hauteur, &largeur);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 64, 64);
	img.img = mlx_xpm_file_to_image(vars.mlx, pers, &hauteur, &largeur);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 32, 32);
	mlx_key_hook(vars.win, close_test, &vars);
	mlx_loop(vars.mlx);
}