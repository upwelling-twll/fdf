/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:40:27 by nmagdano          #+#    #+#             */
/*   Updated: 2024/04/04 20:08:16 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#ifndef SENS 
# define SENS 50
#endif
#ifndef RAD
# define RAD 0.2
#endif
#ifndef ZOOM
# define ZOOM 1
#endif
#ifndef WIN_HI
# define WIN_HI 1100
#endif
#ifndef WIN_WI
# define WIN_WI 2500
#endif
#ifndef ISO
# define ISO 1
#endif

void	set_parameters(t_map **mdata)
{
	(*mdata)->win_height = WIN_HI;
	(*mdata)->win_wight = WIN_WI;
	(*mdata)->shift_y = 0;
	(*mdata)->shift_x = 0;
	(*mdata)->zoom = adapt((min((*mdata)->win_height, (*mdata)->win_wight)
				/ max((*mdata)->line_len, (*mdata)->line_num) / 4), *mdata);
	if ((*mdata)->zoom <= 0)
	{
		(*mdata)->zoom = (min((*mdata)->win_height, (*mdata)->win_wight)
				/ max((*mdata)->line_len, (*mdata)->line_num) / 2);
	}
	(*mdata)->rad = 0.785398;
	(*mdata)->iso_grow = 1;
	(*mdata)->two_d = 0;
	(*mdata)->perspective = 0;
}

int	identify_key(int key)
{
	if (key == 126 || key == 65362)
		return (1);
	if (key == 125 || key == 65364)
		return (1);
	if (key == 123 || key == 65363)
		return (1);
	if (key == 124 || key == 65361)
		return (1);
	if (key == 119 || key == 13)
		return (1);
	if (key == 115 || key == 1)
		return (1);
	if (key == 97 || key == 2)
		return (1);
	if (key == 100 || key == 0)
		return (1);
	if (key == 65451 || key == 69 || key == 34 || key == 31)
		return (1);
	if (key == 65453 || key == 78 || key == 111 || key == 105)
		return (1);
	return (0);
}

int	execute_key(int key, t_map **mdata)
{
	if (key == 126 || key == 65362)
		(*mdata)->shift_y -= SENS;
	if (key == 125 || key == 65364)
		(*mdata)->shift_y += SENS;
	if (key == 123 || key == 65363)
		(*mdata)->shift_x -= SENS;
	if (key == 124 || key == 65361)
		(*mdata)->shift_x += SENS;
	if (key == 119 || key == 13)
		(*mdata)->rad -= RAD;
	if (key == 115 || key == 1)
		(*mdata)->rad += RAD;
	if (key == 97 || key == 2)
		(*mdata)->rad -= RAD;
	if (key == 100 || key == 0)
		(*mdata)->rad += RAD;
	if (key == 65451 || key == 69)
		(*mdata)->zoom += ZOOM;
	if (key == 65453 || key == 78)
		(*mdata)->zoom -= ZOOM;
	if (key == 31 || key == 111)
		(*mdata)->iso_grow -= ISO;
	if (key == 34 || key == 105)
		(*mdata)->iso_grow += ISO;
	return (execute_key2(key, mdata));
}

void	new_window(t_map *mdata)
{
	mlx_destroy_window(mdata->mlx_ptr, mdata->win_ptr);
	(mdata)->win_height = 1395;
	(mdata)->win_wight = 2560;
	mdata->mlx_ptr = mlx_init();
	mdata->win_ptr = mlx_new_window(mdata->mlx_ptr, mdata->win_wight,
			mdata->win_height, "FDF");
	draw_map(mdata);
	mlx_hook(mdata->win_ptr, 17, 1L << 17, close_window, mdata);
	mlx_key_hook(mdata->win_ptr, catch_key, mdata);
	mlx_loop(mdata->mlx_ptr);
}

int	catch_key(int key, t_map *mdata)
{
	ft_printf("%d\n", key);
	// if (key == 3)
	// {
	// 	new_window(mdata);
	// 	return (0);
	// }
	if (identify_key(key) || identify_key2(key))
	{
		mlx_clear_window(mdata->mlx_ptr, mdata->win_ptr);
		execute_key(key, &mdata);
		draw_map(mdata);
	}
	else if (key == 65307 || key == 53 || key == 17)
	{
		mlx_destroy_window(mdata->mlx_ptr, mdata->win_ptr);
		exit_fdf(&mdata, 0);
		exit (0);
		return (0);
	}
	else
		ft_printf("- Key is invalid\n");
	return (0);
}
