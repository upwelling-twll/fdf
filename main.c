//#include "./mlx_linux/mlx.h"
//#include "minilibx/mlx.h"
#include "fdf.h"
#ifndef SENS
# define SENS 20
#endif
#ifndef RAD
# define RAD 0.2
#endif
#ifndef ZOOM
# define ZOOM 5
#endif
#ifndef WIN_HI
# define WIN_HI 1000
#endif
#ifndef WIN_WI
# define WIN_WI 1800
#endif

int	deal_key(int key, t_map *mdata)
{
	ft_printf("%d\n", key);

	if (key == 126 || key == 65364) //up (mac || linux)
		mdata->shift_y -= SENS;
	if (key == 125 || key == 65362) //down
		mdata->shift_y += SENS;
	if (key == 123 || key == 65363) //right
		mdata->shift_x -= SENS;
	if (key == 124 || key == 65361) //left
		mdata->shift_x += SENS;
	if (key == 119) //up (linux)
		mdata->rad -= RAD;
	if (key == 115) //down
		mdata->rad += RAD;
	if (key == 97) //right
		mdata->rad -= RAD;
	if (key == 100) //left
		mdata->rad += RAD;
	if (key == 65451) //zoom+ linux
		mdata->zoom += ZOOM;
	if (key == 65453) //zoom-
		mdata->zoom -= ZOOM;
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
	printf("JI\n");
	if ((file = get_file(*argv)) == NULL)
		return (1);
	printf("file name:%s\n", file);
	if (parse_map(file, &mdata))
		return (exit_fdf(&mdata, 1));
	printf("in main parsed\n");
	print_map_matrix(mdata);
	//start drawing:
	printf("hi\n");
	mdata->win_height = WIN_HI;
	mdata->win_wight = WIN_WI;
	mdata->mlx_ptr = mlx_init();
	mdata->win_ptr = mlx_new_window(mdata->mlx_ptr, mdata->win_wight, mdata->win_height, "FDF");
	//make_frameware(0, 0, 0, 0, mdata);
	mdata -> zoom = 20;
	mdata->rad = 0.785398;
	draw_map(mdata);
	mlx_key_hook(mdata->win_ptr, deal_key, mdata); // for bonus
	mlx_loop(mdata->mlx_ptr); 
	exit_fdf(&mdata, 0);
	return (0);
	//return (exit_fdf(&mdata, 0));
}
