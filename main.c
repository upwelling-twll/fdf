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

	if (check_fd(fd) || parse_map(fd, &mdata))
		return (exit_fdf(&mdata, 1));
	//print_map(mdata);
	return (0);
}

int	main(int argc, char *argv[])
{
	char	*file;
	int 	fd;

	if (argc != 2)
		return (1);
	file = get_file(*argv);
	fd = open(file, O_RDONLY);
//	fd = open("folder", O_RDONLY);
	if (fdf(3))
		write(2, "ERROR to main\n", 15);
	close(fd);
	return (0);
}
