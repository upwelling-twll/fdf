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
# define WIN_WI 1000
#endif
#ifndef ISO
# define ISO 10
#endif

int	identify_key(int key)
{
	if (key == 126 || key == 65362) //move up (mac || linux)
		return (1);
	if (key == 125 || key == 65364) //down
		return (1);
	if (key == 123 || key == 65363) //right
		return (1);
	if (key == 124 || key == 65361) //left
		return (1);
	if (key == 119 || key == 13) //rotate up (linux)
		return (1);
	if (key == 115 || key == 1) //down
		return (1);
	if (key == 97 || key == 2) //right
		return (1);
	if (key == 100 || key == 0) //left
		return (1);
	if (key == 65451 || key == 69 || key == 22 || key == 26) //zoom+ (linux || mac) || iso_grow(mac)
		return (1);
	if (key == 65453 || key == 78) //zoom-
		return (1);
	return (0);
}

int	execute_key(int key, t_map *mdata)
{
	if (key == 126 || key == 65362) //move up (mac || linux)
		mdata->shift_y -= SENS;
	if (key == 125 || key == 65364) //down
		mdata->shift_y += SENS;
	if (key == 123 || key == 65363) //right
		mdata->shift_x -= SENS;
	if (key == 124 || key == 65361) //left
		mdata->shift_x += SENS;
	if (key == 119 || key == 13) //rotate up (linux)
		mdata->rad -= RAD;
	if (key == 115 || key == 1) //down
		mdata->rad += RAD;
	if (key == 97 || key == 2) //right
		mdata->rad -= RAD;
	if (key == 100 || key == 0) //left
		mdata->rad += RAD;
	if (key == 65451 || key == 69) //zoom+ linux
		mdata->zoom += ZOOM;
	if (key == 65453 || key == 78) //zoom-
		mdata->zoom -= ZOOM;
	if (key == 26) //z isometry lower -
		mdata->iso_grow -= ISO;
	if (key == 22) //z isometry heigher-
		mdata->iso_grow += ISO;
	return (0);
}

int	deal_key(int key, t_map *mdata)
{
	ft_printf("%d\n", key);

	if (identify_key(key))
		execute_key(key, mdata);
	if (key == 65307 || key == 53) //escape
	{
		mlx_destroy_window(mdata->mlx_ptr, mdata->win_ptr);
		exit_fdf(&mdata, 0);
		exit (0);
	}
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

void	set_parameters(t_map **mdata)
{
	(*mdata)->win_height = WIN_HI;
	(*mdata)->win_wight = WIN_WI;
	(*mdata)->zoom = 20;
	(*mdata)->rad = 0.785398;
	(*mdata)->iso_grow = 0;
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
	{
		ft_printf("error\n");
		return (1);
	}
	if (parse_map(file, &mdata))
		return (exit_fdf(&mdata, 1));
	print_map_matrix(mdata);
	//start drawing:
	set_parameters(&mdata);
	mdata->mlx_ptr = mlx_init();
	mdata->win_ptr = mlx_new_window(mdata->mlx_ptr, mdata->win_wight, mdata->win_height, "FDF");
	//make_frameware(0, 0, 0, 0, mdata);
	draw_map(mdata);
	printf("hook\n");
	mlx_key_hook(mdata->win_ptr, deal_key, mdata); // for bonus
	printf("loop\n");
	mlx_loop(mdata->mlx_ptr); 
	printf("no loop\n");
	exit_fdf(&mdata, 0);
	return (0);
}
