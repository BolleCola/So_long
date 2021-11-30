#include "so_long.h"

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int close(int keycode, t_vars *vars, t_data img)
{
	static int i;
	static int j;
	if (!j)
		j = 320;
	if (!i)
		i = 100;
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit (1);
	}
	if (keycode == 1)
	{
		img.img = mlx_new_image(vars->mlx, 640, 480);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
		my_mlx_pixel_put(&img, j, i++, 0xFF67C5);
		mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	}
	if (keycode == 13)
	{
		img.img = mlx_new_image(vars->mlx, 640, 480);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
		my_mlx_pixel_put(&img, j, i--, 0x6A329F);
		mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	}
	if (keycode == 2)
	{
		img.img = mlx_new_image(vars->mlx, 640, 480);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
		my_mlx_pixel_put(&img, j++, i, 0xFFC0CB);
		mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	}
	if (keycode == 0)
	{
		img.img = mlx_new_image(vars->mlx, 640, 480);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
		my_mlx_pixel_put(&img, j--, i, 0xFFFFFF);
		mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	}
}

int	render_next_frame(t_vars *vars, t_data img)
{
	mlx_hook(vars->win, 2, 1L>>0, close, vars);
}

int main(void)
{
    t_vars vars;
	t_data img;
		
	char *path = "./Grass.xpm";
	int	hauteur = 16;
	int largeur = 16;
	
	vars.mlx = mlx_init();
	img.img = mlx_xpm_file_to_image(vars.mlx, path, &hauteur, &largeur);




	/*vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Bolle's Dungeon");
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);*/





	/*void    *mlx_win;
   	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Bolle's Dungeon !");
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1080, 720, "Bolle's Dungeon");
    img.img = mlx_new_image(mlx, 1080, 720);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	int i = 360;
	int	j = 360;
	while (j != 460)
    	my_mlx_pixel_put(&img, 530, j++, 0xFF67C5);
	while (i != 460)
		my_mlx_pixel_put(&img, 532, i++, 0x6A329F);
	j = 360;
	while (j != 460)
		my_mlx_pixel_put(&img, 534, j++, 0xFFC0CB);
	i = 360;
	while (i != 460)
		my_mlx_pixel_put(&img, 536, i++, 0xFFFFFF);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
	*/
}