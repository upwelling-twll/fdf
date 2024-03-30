#include "fdf.h"

float	get_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

int	continue_drawing(float x, float x1, float y, float y1, float delta_x, float delta_y)
{
	if ((x1 - x) > delta_x*2)
		return (1);
	if ((y1 - y) > delta_y*2)
		return (1);
	return (0);
}

void	add_isometry(float *x, float *y, int z, t_map *mdata)
{
	// 0.785398 is 45 degree in radians
	*x = (*x - *y) * cos(mdata->rad);
	*y = (*x + *y) * sin(mdata->rad) - z;
	//printf("iso x=%f, y=%f, z=%i\n", *x, *y, z);
}

// int get_light(int start, int end, double percentage)
// {
//     return ((int)((1 - percentage) * start + percentage * end));
// }

// int get_color(t_point current, t_point start, t_point end, t_point delta)
// {
//     int     red;
//     int     green;
//     int     blue;
//     double  percentage;

//     if (current.color == end.color)
//         return (current.color);
//     if (delta.x > delta.y)
//         percentage = percent(start.x, end.x, current.x);
//     else
//         percentage = percent(start.y, end.y, current.y);
//     red = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, percentage);
//     green = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, percentage);
//     blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
//     return ((red << 16) | (green << 8) | blue);
// }

void	get_color(t_map **mdata, int z, int z1)
{
	if ( z > 0 || z1 > 0)
		(*mdata)->color = 0xffC2185B;
	else
		(*mdata)->color = 0xffffff;
}

void	zoom(float *x, float *x1, float *y, float *y1, t_map *mdata)
{
	*x = *x * mdata->zoom;
	*y = *y * mdata->zoom;
	*x1 = *x1 * mdata->zoom;
	*y1 = *y1 * mdata->zoom;
}

void	shift_and_centering(float *x, float *x1, float *y, float *y1, t_map *mdata)
{
//shift
	*x += mdata->shift_x;
	*y += mdata->shift_y;
	*x1 += mdata->shift_x;
	*y1 += mdata->shift_y;
//centering
	*x += mdata->win_wight / 2 - (mdata->line_len / 2) ;
	*y += mdata->win_height / 2 - (mdata->line_num / 2);
	*x1 += mdata->win_wight / 2 - (mdata->line_len / 2);
	*y1 += mdata->win_height / 2 - (mdata->line_num / 2);
}

int	make_frameware(float x, float x1, float y, float y1, t_map *mdata)
{
	float	delta_x;
	float	delta_y;
	float		max;
	int		z;
	int		z1;

	// printf("mdata sent to frameware\n");
	// print_map_matrix(mdata);
	z = mdata->matrix[(int)y][(int)x];
	z1 = mdata->matrix[(int)y1][(int)x1];
	//zoom
	zoom(&x, &x1, &y, &y1, mdata);
	//color
	get_color(&mdata, z, z1);
	// printf("X=%f, Y=%f, Z= %d\n", x, y, z);
	// printf("X1=%f, Y1=%f, Z1= %d\n", x1, y1, z1);
	//isometry
	add_isometry(&x, &y, z, mdata);
	add_isometry(&x1, &y1, z1, mdata);
	//shift
	shift_and_centering(&x, &x1, &y, &y1, mdata);
	// printf("shift X=%f, Y=%f, Z= %d\n", x, y, z);
	// printf("shift X1=%f, Y1=%f, Z1= %d\n", x1, y1, z1);
	max = fabs(get_max(x1 - x, y1 - y));
	delta_x = (x1 - x) / max;
	delta_y = (y1 - y) / max;
	// printf("delta_x: %f\n", delta_x);
	// printf("delta_y: %f\n", delta_y);
	int counter = 0;
	while (fabs(x1 - x) > fabs(delta_x * 2) || fabs(y1 - y) > fabs(delta_y * 2))
	{
		printf("counter: %i\n, point X=%f, Y=%f, Z= %d\n", counter, x, y, z);
		mlx_pixel_put(mdata->mlx_ptr, mdata->win_ptr, x, y, mdata->color);
		x += delta_x;
		y += delta_y;
		counter++;
		if (counter > 6)
			break;
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
		while (x < (int)mdata->line_len)
		{
			//printf("draw iter: x=%d, y=%d\n", x, y);
			if (x < (int)mdata->line_len - 1)
			{
				//printf("print x+1\n");
				make_frameware(x, x + 1, y, y, mdata); //horisontal line
			}
			if (y < mdata->line_num - 1)
			{
				//printf("print y+1\n");
				make_frameware(x, x, y, y + 1, mdata); //vertical line
			}
			x++;
		}
		y++;
	}
}
