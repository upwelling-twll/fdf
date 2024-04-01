#include "fdf.h"

float	get_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

int	make_frameware(float x, float x1, float y, float y1, t_map *mdata)
{
	float	delta_x;
	float	delta_y;
	float	max;
	int		z;
	int		z1;

	z = mdata->matrix[(int)y][(int)x];
	z1 = mdata->matrix[(int)y1][(int)x1] ;
	zoom(&x, &x1, &y, &y1, mdata);
	get_color(&mdata, z, z1);
	add_isometry(&x, &y, z, mdata);
	add_isometry(&x1, &y1, z1, mdata);
	shift_and_centering(&x, &x1, &y, &y1, mdata);
	max = get_max(fabs(x1 - x), fabs(y1 - y));
	delta_x = (x1 - x) / max;
	delta_y = (y1 - y) / max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		my_mlx_pixel_put(mdata, x, y, mdata->color);
		x += delta_x;
		y += delta_y;
		if (x > mdata->win_wight || y > mdata->win_height || y < 0 || x < 0)
			break;
	}
	return (0);
}

void	make_img(t_map *mdata)
{
	if (mdata->img_d.img == NULL)
	{
		mdata->img_d.img = mlx_new_image(mdata->mlx_ptr, mdata->win_wight, mdata->win_height);
		mdata->img_d.addr = mlx_get_data_addr(mdata->img_d.img,  &mdata->img_d.bits_per_pix, &mdata->img_d.line_length, &mdata->img_d.endian);
	}
	else
	{
		ft_bzero(mdata->img_d.addr, mdata->win_wight * mdata->win_height * (mdata->img_d.bits_per_pix / 8));
	}
}

void	draw_map(t_map *mdata)
{
	int		x;
	int		y;

	y = 0;
	make_img(mdata);
	while (mdata->matrix[y])
	{
		x = 0;
		while (1)
		{
			if (mdata->matrix[y + 1])
				make_frameware(x, x, y + 1, y, mdata);
			if ((x < (int)mdata->line_len - 1))
				make_frameware(x, x + 1, y, y, mdata);
			if (x == (int)mdata->line_len - 1)
				break;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mdata->mlx_ptr, mdata->win_ptr, mdata->img_d.img, 0, 0);
}
