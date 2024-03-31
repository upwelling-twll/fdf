#include "fdf.h"
#ifndef SENS
# define SENS 50
#endif
#ifndef RAD
# define RAD 0.2
#endif
#ifndef ZOOM
# define ZOOM 10
#endif
#ifndef WIN_HI
# define WIN_HI 1000
#endif
#ifndef WIN_WI
# define WIN_WI 2000
#endif
#ifndef ISO
# define ISO 1
#endif

void	set_parameters(t_map **mdata)
{
	(*mdata)->win_height = WIN_HI;
	(*mdata)->win_wight = WIN_WI;
	(*mdata)->shift_y = 0;
	(*mdata)->shift_x = 0;
	(*mdata)->zoom = 20;
	(*mdata)->rad = 0.785398;
	(*mdata)->iso_grow = 1;
}

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
	if (key == 65451 || key == 69 || key == 34 || key == 31) //zoom+ (linux || mac) || iso_grow(mac)
		return (1);
	if (key == 65453 || key == 78) //zoom-
		return (1);
	return (0);
}

int	execute_key(int key, t_map **mdata)
{
	if (key == 126 || key == 65362) //move up (mac || linux)
		(*mdata)->shift_y -= SENS;
	if (key == 125 || key == 65364) //down
		(*mdata)->shift_y += SENS;
	if (key == 123 || key == 65363) //right
		(*mdata)->shift_x -= SENS;
	if (key == 124 || key == 65361) //left
		(*mdata)->shift_x += SENS;
	if (key == 119 || key == 13) //rotate up (linux)
		(*mdata)->rad -= RAD;
	if (key == 115 || key == 1) //down
		(*mdata)->rad += RAD;
	if (key == 97 || key == 2) //right
		(*mdata)->rad -= RAD;
	if (key == 100 || key == 0) //left
		(*mdata)->rad += RAD;
	if (key == 65451 || key == 69) //zoom+ linux
		(*mdata)->zoom += ZOOM;
	if (key == 65453 || key == 78) //zoom-
		(*mdata)->zoom -= ZOOM;
	if (key == 31) //z isometry lower -
		(*mdata)->iso_grow -= ISO;
	if (key == 34) //z isometry heigher+
		(*mdata)->iso_grow += ISO;
	return (0);
}

void	new_window(t_map *mdata)
{
	mlx_destroy_window(mdata->mlx_ptr, mdata->win_ptr);
	(mdata)->win_height = 1400;
	(mdata)->win_wight = 2560;
	mdata->mlx_ptr = mlx_init();
	mdata->win_ptr = mlx_new_window(mdata->mlx_ptr, mdata->win_wight, mdata->win_height, "FDF");
	draw_map(mdata);
	mlx_key_hook(mdata->win_ptr, catch_key, mdata); // for bonus
	mlx_loop(mdata->mlx_ptr); 
}

int	catch_key(int key, t_map *mdata)
{
	ft_printf("%d\n", key);

	if (identify_key(key))
		execute_key(key, &mdata);
	if (key == 65307 || key == 53) //escape
	{
		mlx_destroy_window(mdata->mlx_ptr, mdata->win_ptr);
		exit_fdf(&mdata, 0);
		exit (0);
	}
	if (key == 3) //key "f" - fullscreen
	{
		new_window(mdata);
		return (0);
	}
	mlx_clear_window(mdata->mlx_ptr, mdata->win_ptr);
	draw_map(mdata);
	return (0);
}
