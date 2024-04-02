/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_fdf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:40:27 by nmagdano          #+#    #+#             */
/*   Updated: 2024/04/02 16:15:23 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_line(int *line, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		printf("%3d", line[i]);
		printf(" ");
		i++;
	}
}

void	print_color_line(unsigned int *line, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		printf("%3u", line[i]);
		printf(" ");
		i++;
	}
}

void	print_color_matrix(t_map *mdata)
{
	size_t	i;

	i = 0;
	printf("\n***		color matrix		***\n");
	printf("mdata->line_num:%i\n", mdata->line_num);
	printf("mdata->line_len:%lu\n", mdata->line_len);
	while ((mdata)->matrix[i])
	{
		print_color_line((mdata)->color_m[i], (mdata)->line_len);
		printf("\n");
		i++;
	}
}

void	print_map_matrix(t_map *mdata)
{
	size_t	i;

	i = 0;
	printf("\n***		matrix		***\n");
	printf("mdata->line_num:%i\n", mdata->line_num);
	printf("mdata->line_len:%lu\n", mdata->line_len);
	while ((mdata)->matrix[i])
	{
		print_line((mdata)->matrix[i], (mdata)->line_len);
		printf("\n");
		i++;
	}
}

void	print_pars_result(t_map *map)
{
	printf("\n***		map parsing result		***\n");
	printf("line_len:%lu\n", map->line_len);
	printf("line_num:%i\n", map->line_num);
	printf("***			***			***\n");
}
