#include "mlx_linux/mlx.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pix;
	int		line_length;
	int		endian;
}				t_data;

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
	int i;
	int	y;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1010, 1010, "Hakuna Matata!");
	img.img = mlx_new_image(mlx, 1010, 1010);
	img.addr = mlx_get_data_addr(img.img, &(img.bits_per_pix), &(img.line_length), &(img.endian));
	i = 200;
	y = 900;
	while ( i < 250)
	{
		my_mlx_pixel_put(&img, i, i, 0x00FF0000);
		i--;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}