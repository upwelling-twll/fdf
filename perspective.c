/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:40:27 by nmagdano          #+#    #+#             */
/*   Updated: 2024/04/04 21:16:18 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	project_point(float *x, float *y, int *z, t_map *mdata)
{
	float	depth;

	if (*z - mdata->camera_depth == 0)
		depth =  mdata->perspective_factor;
	else
		depth =  mdata->perspective_factor / (*z - mdata->camera_depth);
	*x = (*x * depth);
	*y = (*y * depth);
	// *x = (*x * 0.5);
	// *y = (*y * 0.5);
}

void	rotate_yaw(t_map **mdata, int *z)
{
	float	cos_angle;
	float	sin_angle;

	cos_angle = cos((*mdata)->yaw);
	sin_angle = sin((*mdata)->yaw);
	(*mdata)->x = (*mdata)->x * cos_angle + *z * sin_angle;
	*z = (*mdata)->x * sin_angle + *z * cos_angle;
}

void	rotate_pitch(t_map **mdata, int *z)
{
	float	cos_angle;
	float	sin_angle;

	cos_angle = cos((*mdata)->pitch);
	sin_angle = sin((*mdata)->pitch);
	(*mdata)->y = (*mdata)->y * cos_angle - *z * sin_angle;
	*z = (*mdata)->y * cos_angle - *z * cos_angle;
}

void	build_perspective(t_map **mdata)
{
	(*mdata)->perspective = 1;
	(*mdata)->perspective_factor = 100;
	(*mdata)->win_center_h = (*mdata)->win_height / 2;
	(*mdata)->win_center_w = (*mdata)->win_wight / 2;
	(*mdata)->camera_depth = 20;
	(*mdata)->yaw = 45;
	(*mdata)->pitch = 30;
	(*mdata)->yaw = (*mdata)->yaw * (M_PI / 180.0);
	(*mdata)->pitch = (*mdata)->pitch * (M_PI / 180.0);
	return ;
}
