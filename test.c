#include "so_long.h"

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		key_hook(int keycode, t_vars *vars)
{
	printf("la touche a bien ete hook !!!\n");
}

int main(void)
{
    /*void    *mlx;
    void    *mlx_win;
    t_data  img;*/

	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Bolle's Dungeon !");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);

    /*mlx = mlx_init();
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