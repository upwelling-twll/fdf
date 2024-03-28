#include "fdf.h"

int	get_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

int	continue_drawing(float x, float x1, float y, float y1)
{
	if ((int)(x - x1) != 0)
		return (1);
	if ((int)(y - y1) != 0)
		return (1);
	return (0);
}

void	add_isometry(float *x, float *y, int z)
{
	// *x = (*x - *y) * cos(0.8);
	// *y = (*x + *y) * sin(0.8) - z;
	printf("iso x=%f, y=%f, z=%i\n", (*x - *y) * cos(0.8), (*x + *y) * sin(0.8) - z, z);
}

int	make_frameware(float x, float x1, float y, float y1, t_map *mdata)
{
	float	delta_x;
	float	delta_y;
	int		max;
	int		z;
	int		z1;

	// printf("mdata sent to frameware\n");
	// print_map_matrix(mdata);
	z = mdata->matrix[(int)y][(int)x];
	z1 = mdata->matrix[(int)y1][(int)x1];
	//zoom
	printf("X=%f, Y=%f, Z= %d\n", x, y, z);
	x = x * mdata->zoom;
	y = y * mdata->zoom;
	x1 = x1 * mdata->zoom;
	y1 = y1 * mdata->zoom;

	//color
	if ( z > 0 || z1 > 0)
		mdata->color = 0xffC2185B;
	else
		mdata->color = 0xffffff;
	//isometry
	add_isometry(&x, &y, z);
	add_isometry(&x1, &y1, z1);
	//shift
	x += mdata->shift_x;
	y += mdata->shift_y;
	x1 += mdata->shift_x;
	y1 += mdata->shift_y;

	delta_x = x1 - x;
	delta_y = y1 - y;

	max = get_max(delta_x, delta_y);
	delta_x = delta_x / max;
	delta_y = delta_y / max;
	while (continue_drawing(x, x1, y, y1))
	{
		mlx_pixel_put(mdata->mlx_ptr, mdata->win_ptr, x, y, mdata->color);
		x += delta_x;
		y += delta_y;
	}
	return (0);
}

void	draw_map(t_map *mdata)
{
	int	x;
	int	y;

	y = 0;
	while (y < mdata->line_num)
	{
		x = 0;
		while ((int)x < (int)mdata->line_len)
		{
			printf("draw iter: x=%d, y=%d\n", x, y);
			if ((int)x < (int)mdata->line_len - 1)
			{
				printf("print x+1\n");
				make_frameware(x, x + 1, y, y, mdata); //horisontal line
			}
			if (y < mdata->line_num - 1)
			{
				printf("print y+1\n");
				make_frameware(x, x, y, y + 1, mdata); //vertical line
			}
			x++;
		}
		y++;
	}
}
