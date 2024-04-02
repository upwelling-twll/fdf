/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:40:27 by nmagdano          #+#    #+#             */
/*   Updated: 2024/04/02 16:21:34 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_map *mdata, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < mdata->win_wight && y >= 0 && y < mdata->win_height)
	{
		dst = mdata->img_d.addr + (y * mdata->img_d.line_length + x
				* (mdata->img_d.bits_per_pix / 8));
		*(unsigned int *)dst = color;
	}
}

int	close_window(t_map *mdata)
{
	mlx_destroy_image(mdata->mlx_ptr, mdata->img_d.img);
	mlx_destroy_window(mdata->mlx_ptr, mdata->win_ptr);
	exit_fdf(&mdata, 0);
	exit (0);
	return (0);
}

int	main(int argc, char *argv[])
{
	char	*file;
	t_map	*mdata;

	mdata = NULL;
	if (argc != 2)
		return (1);
	argv++;
	file = get_file(*argv);
	if (file == NULL)
		return (exit_fdf(NULL, 10));
	if (parse_map(file, &mdata))
		return (exit_fdf(&mdata, 1));
	set_parameters(&mdata);
	mdata->img_d.img = NULL;
	mdata->mlx_ptr = mlx_init();
	mdata->win_ptr = mlx_new_window(mdata->mlx_ptr, mdata->win_wight,
			mdata->win_height, "FDF");
	draw_map(mdata);
	mlx_hook(mdata->win_ptr, 17, 1L << 17, close_window, mdata);
	mlx_key_hook(mdata->win_ptr, catch_key, mdata);
	mlx_loop(mdata->mlx_ptr);
	exit_fdf(&mdata, 0);
	return (0);
}
