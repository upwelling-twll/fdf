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

// int fdf(int	fd)
// {

// }

int	main(int argc, char *argv[])
{
	char	*file;
	int 	fd;
	t_map	*mdata;

	mdata = NULL;
	if (argc != 2)
		return (1);
	argv++;
	file = get_file(*argv);
	printf("file name:%s\n", file);
	fd = open(file, O_RDONLY);
	if (check_fd(fd) || parse_map(fd, &mdata))
		return (exit_fdf(&mdata, 1));
	close(fd);
	fd = open(file, O_RDONLY);
	printf("line_num in main:%i\n", mdata->line_num);
	save_map(fd, &mdata);
	//print_map_matrix(mdata);
	close(fd);
	//free(mdata->matrix);
	return (0);
	//return (exit_fdf(&mdata, 0));
}
