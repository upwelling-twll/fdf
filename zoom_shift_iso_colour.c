#include "fdf.h"

void	add_isometry(float *x, float *y, int z, t_map *mdata)
{
	*x = (*x - *y) * cos(mdata->rad);
	*y = (*x + *y) * sin(mdata->rad) - (z * mdata->iso_grow);
}

void	get_color(t_map **mdata, int z, int z1)
{
	if (z > 0 || z1 > 0)
		(*mdata)->color = 0x008800;
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
	*x += mdata->shift_x;
	*y += mdata->shift_y;
	*x1 += mdata->shift_x;
	*y1 += mdata->shift_y;
	*x += mdata->win_wight / 2 - (mdata->line_len / 2);
	*y += mdata->win_height / 2 - (mdata->line_num / 2);
	*x1 += mdata->win_wight / 2 - (mdata->line_len / 2);
	*y1 += mdata->win_height / 2 - (mdata->line_num / 2);
}
