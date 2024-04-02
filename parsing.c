/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:40:27 by nmagdano          #+#    #+#             */
/*   Updated: 2024/04/02 17:01:03 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_line_num(char *file)
{
	int		fd;
	int		n;
	char	*str;

	n = 0;
	fd = open(file, O_RDONLY);
	if (fd < 2)
		return (-1);
	str = get_next_line(fd);
	while (str != NULL)
	{
		n++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (n);
}

int	width_split(char *str, char c)
{
	char	**arr;
	int		i;

	i = 0;
	arr = fdf_split(str, c);
	if (arr && arr[0])
	{
		while (arr[i])
		{
			i++;
		}
		clean_split(arr, i);
	}
	if (arr)
		free(arr);
	return (i);
}

int	get_line_len_read_and_split(int fd, int *len)
{
	char	*str;
	int		i;

	*len = 0;
	str = get_next_line(fd);
	if (str != NULL)
	{
		*len = width_split(str, ' ');
		free(str);
		i = 1;
		str = get_next_line(fd);
		while (str != NULL && width_split(str, ' ') >= *len)
		{
			free(str);
			i++;
			str = get_next_line(fd);
		}
		if (str)
			return (free_ret(fd, str, -2));
	}
	else
		return (free_ret(fd, NULL, -1));
	return (free_ret(fd, NULL, *len));
}

int	get_line_len(char *file)
{
	int		fd;
	int		len;

	fd = open(file, O_RDONLY);
	if (fd <= 2)
		return (-1);
	if (get_line_len_read_and_split(fd, &len) == -1)
		return (-1);
	return (len);
}

int	parse_map(char *file, t_map **mdata)
{
	int		i;

	i = 0;
	*mdata = malloc(sizeof(t_map));
	(*mdata)->line_len = 0;
	(*mdata)->line_num = 0;
	i = get_line_num(file);
	if (i > 0)
		(*mdata)->line_num = i;
	i = get_line_len(file);
	if (i > 0)
		(*mdata)->line_len = i;
	else
		return (1);
	if (fill_matrix(mdata, file))
		return (1);
	return (0);
}
