//#include "./mlx_linux/mlx.h"
//#include "minilibx/mlx.h"
#include "fdf.h"
# ifndef SENS
# define SENS 20
#endif

int	deal_key(int key, t_map *mdata)
{
	ft_printf("%d\n", key);

	if (key == 126) //up
		mdata->shift_y -= SENS;
	if (key == 125) //down
		mdata->shift_y += SENS;
	if (key == 123) //up
		mdata->shift_x -= SENS;
	if (key == 124) //up
		mdata->shift_x += SENS;
	mlx_clear_window(mdata->mlx_ptr, mdata->win_ptr);
	draw_map(mdata);
	return (0);
}

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
	//start drawing:
	mdata->mlx_ptr = mlx_init();
	mdata->win_ptr = mlx_new_window(mdata->mlx_ptr, 1000, 1000, "FDF");
	//make_frameware(10, 100, 600, 100, mdata);
	mdata -> zoom = 20;
	draw_map(mdata);
	mlx_key_hook(mdata->win_ptr, deal_key, mdata); // for bonus
	mlx_loop(mdata->mlx_ptr); 
	exit_fdf(&mdata, 0);
	return (0);
	//return (exit_fdf(&mdata, 0));
}
