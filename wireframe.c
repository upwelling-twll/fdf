/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wireframe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:40:27 by nmagdano          #+#    #+#             */
/*   Updated: 2024/04/01 23:31:16 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	get_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

int	make_frameware(t_map *m)
{
	float	delta_x;
	float	delta_y;
	float	max;
	int		z;
	int		z1;

	z = m->matrix[(int)m->y][(int)m->x];
	z1 = m->matrix[(int)m->y1][(int)m->x1];
	zoom(m);
	get_color(&m, z, z1);
	add_isometry(&m->x, &m->y, z, m);
	add_isometry(&m->x1, &m->y1, z1, m);
	shift_and_centering(m);
	max = get_max(fabs(m->x1 - m->x), fabs(m->y1 - m->y));
	delta_x = (m->x1 - m->x) / max;
	delta_y = (m->y1 - m->y) / max;
	while ((int)(m->x - m->x1) || (int)(m->y - m->y1))
	{
		my_mlx_pixel_put(m, m->x, m->y, m->color);
		m->x += delta_x;
		m->y += delta_y;
		if (m->x > m->win_wight || m->y > m->win_height || m->y < 0 || m->x < 0)
			break ;
	}
	return (0);
}

void	make_img(t_map *mdata)
{
	if (mdata->img_d.img == NULL)
	{
		mdata->img_d.img = mlx_new_image(mdata->mlx_ptr, mdata->win_wight,
				mdata->win_height);
		mdata->img_d.addr = mlx_get_data_addr(mdata->img_d.img,
				&mdata->img_d.bits_per_pix, &mdata->img_d.line_length,
				&mdata->img_d.endian);
	}
	else
	{
		ft_bzero(mdata->img_d.addr, mdata->win_wight * mdata->win_height
			* (mdata->img_d.bits_per_pix / 8));
	}
}

t_map	*ords_plus(t_map *mdata, int x, int y, int flag)
{
	mdata->y = y;
	mdata->x = x;
	mdata->y1 = y;
	mdata->x1 = x;
	if (flag == 1)
		mdata->y += 1;
	if (flag == 2)
		mdata->x += 1;
	return (mdata);
}

void	draw_map(t_map *mdata)
{
	int		y;
	int		x;

	y = 0;
	make_img(mdata);
	while (mdata->matrix[y])
	{
		x = 0;
		while (1)
		{
			if (mdata->matrix[y + 1])
				make_frameware(ords_plus(mdata, x, y, 1));
			if ((x < (int)mdata->line_len - 1))
				make_frameware(ords_plus(mdata, x, y, 2));
			if (x == (int)mdata->line_len - 1)
				break ;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mdata->mlx_ptr, mdata->win_ptr,
		mdata->img_d.img, 0, 0);
}
