/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:40:27 by nmagdano          #+#    #+#             */
/*   Updated: 2024/04/01 21:48:20 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	copy_to_matrix(int *mtx_line, char *str, int len)
{
	int		i;
	int		num;
	char	**nums_str;
	int		cplen;

	i = 0;
	cplen = len;
	nums_str = ft_split(str, ' ');
	while (cplen)
	{
		num = ft_atoi(nums_str[i]);
		mtx_line[i] = num;
		i++;
		cplen--;
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
		if (copy_to_matrix((*mdata)->matrix[i], str, (*mdata)->line_len))
		{
			close(fd);
			return (1);
		}
		i++;
		free(str);
		str = get_next_line(fd);
	}
	(*mdata)->matrix[i] = NULL;
	close(fd);
	return (0);
}

int	fill_matrix(t_map **mdata, char *file)
{
	int		i;

	i = 0;
	(*mdata)->matrix = (int **)malloc(sizeof(int *) * ((*mdata)->line_num) + 1);
	while (i <= (*mdata)->line_num)
	{
		(*mdata)->matrix[i] = (int *)malloc(sizeof(int) * ((*mdata)->line_len));
		i++;
	}
	if (open_and_copy(mdata, file))
		return (1);
	return (0);
}
