#include <fdf.h>

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

int	make_frameware(float x, float x1, float y, float y1, t_map *mdata)
{
	float	delta_x;
	float	delta_y;
	int		max;

	delta_x = x1 - x;
	delta_y = y1 - y;

	max = get_max(delta_x, delta_y);
	delta_x = delta_x / max;
	delta_y = delta_y / max;
	while (continue_drawing(x, x1, y, y1))
	{
		mlx_pixel_put(mdata->mlx_ptr, mdata->win_ptr, x, y, 0xFFFFFF);
		x += delta_x;
		y += delta_y;
	}

}