/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:40:27 by nmagdano          #+#    #+#             */
/*   Updated: 2024/04/02 17:11:07 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	set_color(char *nums_str, unsigned int *cl_m, int i)
{
	unsigned int	hex;

	if ((ft_strchr(nums_str, ',')))
	{
		hex = check_color_matrix(nums_str);
		if (hex < 0)
			return (1);
		cl_m[i] = hex;
	}
	else
		cl_m[i] = 0;
	return (0);
}

int	copy_to_matrix(int *mtx_line, char *str, int len, unsigned int *cl_m)
{
	int				i;
	char			**nums_str;
	int				cplen;

	i = 0;
	cplen = len;
	nums_str = ft_split(str, ' ');
	while (cplen--)
	{
		set_color(nums_str[i], cl_m, i);
		mtx_line[i] = ft_atoi(nums_str[i]);
		i++;
	}
	clean_all_split(nums_str, len);
	free(nums_str);
	return (0);
}

int	open_and_copy(t_map **mdata, char *file)
{
	int		i;
	int		fd;
	char	*str;

	i = 0;
	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	while (str != NULL)
	{
		if (copy_to_matrix((*mdata)->matrix[i], str, (*mdata)->line_len,
				(*mdata)->color_m[i]))
		{
			close(fd);
			return (1);
		}
		i++;
		free(str);
		str = get_next_line(fd);
	}
	(*mdata)->matrix[i] = NULL;
	(*mdata)->color_m[i] = NULL;
	close(fd);
	return (0);
}

int	fill_matrix(t_map **mdata, char *file)
{
	int		i;

	i = 0;
	(*mdata)->matrix = (int **)malloc(sizeof(int *) * ((*mdata)->line_num) + 1);
	(*mdata)->color_m = (unsigned int **)malloc(sizeof(unsigned int *)
			* ((*mdata)->line_num) + 1);
	while (i <= (*mdata)->line_num)
	{
		(*mdata)->matrix[i] = (int *)malloc(sizeof(int) * ((*mdata)->line_len));
		(*mdata)->color_m[i] = (unsigned int *)malloc(sizeof(unsigned int)
				* ((*mdata)->line_len));
		i++;
	}
	if (open_and_copy(mdata, file))
		return (1);
	return (0);
}
