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
	printf("JI\n");
	if ((file = get_file(*argv)) == NULL)
		return (1);
	printf("file name:%s\n", file);
	// mdata = malloc(sizeof(t_map));
	// mdata->matrix = (int**)malloc(sizeof(int*) * 5);
	// int i = 0;
	// int j = 0;
	// printf("JI\n");
	// while(i < 4)
	// {
	// 	mdata->matrix[i] = (int*)malloc(sizeof(int)*8);
	// 	i++;
	// }
	// for (j = 0; j < 8; j++) 
	// {
   	// 	 mdata->matrix[0][j] = 0;
	// }
	// for (j = 0; j < 8; j++) 
	// {
   	// 	 mdata->matrix[1][j] = 2;
	// }
	// for (j = 0; j < 8; j++) 
	// {
   	// 	 mdata->matrix[2][j] = 3;
	// }
	// for (j = 0; j < 8; j++) 
	// {
   	// 	 mdata->matrix[3][j] = 0;
	// }
	//  mdata->matrix[4] = NULL;
	//  (mdata)->line_num = 4;
	//  (mdata)->line_len = 8;
	//  printf("JI\n");
	if (parse_map(file, &mdata))
		return (exit_fdf(&mdata, 1));
	print_map_matrix(mdata);
	//start drawing:
	printf("hi\n");
	mdata->mlx_ptr = mlx_init();
	mdata->win_ptr = mlx_new_window(mdata->mlx_ptr, 1000, 1000, "FDF");
	//make_frameware(0, 0, 0, 0, mdata);
	mdata -> zoom = 20;
	draw_map(mdata);
	//mlx_key_hook(mdata->win_ptr, deal_key, mdata); // for bonus
	mlx_loop(mdata->mlx_ptr); 
	exit_fdf(&mdata, 0);
	return (0);
	//return (exit_fdf(&mdata, 0));
}
