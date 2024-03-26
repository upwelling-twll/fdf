//#include "./mlx_linux/mlx.h"
//#include "minilibx/mlx.h"
#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pix / 8));
	*(unsigned int*)dst = color;
}


int	main(int argc, char *argv[])
{
	char	*file;
	t_map	*mdata;

	mdata = NULL;
	if (argc != 2)
		return (1);
	argv++;
	if ((file = get_file(*argv)) == NULL)
		return (1);
	printf("file name:%s\n", file);
	if (parse_map(file, &mdata))
		return (exit_fdf(&mdata, 1));
	//save_map(fd, &mdata);
	print_map_matrix(mdata);
	//free(mdata->matrix);
	exit_fdf(&mdata, 0);
	return (0);
	//return (exit_fdf(&mdata, 0));
}
