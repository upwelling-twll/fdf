//#include "./mlx_linux/mlx.h"
//#include "minilibx/mlx.h"
#include "mlx/mlx.h"
#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pix / 8));
	*(unsigned int*)dst = color;
}

int main (void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int 	x;
	int		y;
	//int		z;
	//float		sin_alf;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 1000, "Hakuna Matata!");
	img.img = mlx_new_image(mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &(img.bits_per_pix), &(img.line_length), &(img.endian));
	x = 100;
	y = 100;
//	z = 0;
	//sin_alf = 0.5;

	my_mlx_pixel_put(&img, 100, x, 0x00FF0000);
	while (x < 400)
	{
		my_mlx_pixel_put(&img, 100, x, 0x00FF0000);
		x++;
	}
	while (y < 300)
	{
		my_mlx_pixel_put(&img, y, 400, 0x0000FFFF);
		y++;
	}
	x = 100;
	while (x < 700)
	{
		my_mlx_pixel_put(&img, 300, x, 0x00FFFF00);
		x++;
	}
	
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
