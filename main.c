#include "fdf.h"

int	main(int argc, char *argv[])
{
	char	*file;
	t_map	*mdata;

	mdata = NULL;
	if (argc != 2)
		return (1);
	argv++;
	if ((file = get_file(*argv)) == NULL)
	{
		ft_printf("error\n");
		return (1);
	}
	if (parse_map(file, &mdata))
		return (exit_fdf(&mdata, 1));
	//print_map_matrix(mdata);
	//start drawing
	set_parameters(&mdata);
	mdata->mlx_ptr = mlx_init();
	mdata->win_ptr = mlx_new_window(mdata->mlx_ptr, mdata->win_wight, mdata->win_height, "FDF");
	draw_map(mdata);
	mlx_key_hook(mdata->win_ptr, catch_key, mdata);
	mlx_loop(mdata->mlx_ptr); 
	exit_fdf(&mdata, 0);
	return (0);
}
