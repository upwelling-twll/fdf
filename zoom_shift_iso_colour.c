/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_shift_iso_colour.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:40:27 by nmagdano          #+#    #+#             */
/*   Updated: 2024/04/04 21:17:48 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	add_isometry(float *x, float *y, int z, t_map *mdata)
{
	if (mdata->two_d == 1)
		return ;
	*x = (*x - *y) * cos(mdata->rad);
	*y = (*x + *y) * sin(mdata->rad) - (z * mdata->iso_grow);
	if (mdata->perspective == 1)
	{
		project_point(x, y, &z, mdata);
		printf("\nto proj point: x = %f, y =%f, z=%i\n", *x, *y, z);
		rotate_yaw(&mdata, &z);
		rotate_pitch(&mdata, &z);
		printf("after proj point: x = %f, y =%f, z=%i\n", *x, *y, z);
	}
}

void	get_color(t_map **m, int z, int z1)
{
	if ((*m)->color_m[(int)(*m)->y][(int)(*m)->x] != 0)
		(*m)->color = (*m)->color_m[(int)(*m)->y][(int)(*m)->x];
	else if ((*m)->color_m[(int)(*m)->y1][(int)(*m)->x1] != 0)
		(*m)->color = (*m)->color_m[(int)(*m)->y1][(int)(*m)->x1];
	else if (z > 0 || z1 > 0)
		(*m)->color = 0x008800;
	else
		(*m)->color = 0xffffff;
}

void	zoom(t_map *mdata)
{
	mdata->x = mdata->x * mdata->zoom;
	mdata->y = mdata->y * mdata->zoom;
	mdata->x1 = mdata->x1 * mdata->zoom;
	mdata->y1 = mdata->y1 * mdata->zoom;
}

void	shift_and_centering(t_map *mdata)
{
	mdata->x += mdata->shift_x;
	mdata->y += mdata->shift_y;
	mdata->x1 += mdata->shift_x;
	mdata->y1 += mdata->shift_y;
	mdata->x += mdata->win_wight / 2 - (mdata->line_len / 2);
	mdata->y += mdata->win_height / 2 - (mdata->line_num / 2);
	mdata->x1 += mdata->win_wight / 2 - (mdata->line_len / 2);
	mdata->y1 += mdata->win_height / 2 - (mdata->line_num / 2);
}
