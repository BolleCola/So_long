#include "so_long.h"

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int close(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit (1);
	}
	printf("test : %d\n", keycode);
}

int	render_next_frame(t_vars *vars)
{
	mlx_hook(vars->win, 2, 1L>>0, close, vars);
}

int put_pixel(t_data *img)
{

}

int main(void)
{
    void *mlx;
	t_vars *vars;
	t_data *img;

	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 640, 480, "Bolle's Dungeon !!!");
	mlx_loop_hook(vars->mlx, render_next_frame, vars);
	mlx_loop(vars->mlx);
	
	img->mlx = mlx_init(); // ecrire un pixel quand j'appuie sur une touche
	
	
	/*void    *mlx;
    void    *mlx_win;
    t_data  img;

	t_vars	vars;

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
    mlx_loop(mlx);*/
}