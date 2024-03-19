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

int fdf(int	fd)
{
	t_map	*mdata;

	if (parse_map(fd, &mdata))
		return (0);	
	//print_map(mdata);
	return (0);
}

int	main(void)
{
	int fd;

	fd = open("file.txt", O_RDONLY);
	fdf(fd);
	close(fd);
	return (0);
}
