/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:40:27 by nmagdano          #+#    #+#             */
/*   Updated: 2024/04/02 17:04:54 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*clean_col_matrix(t_map **mdata)
{
	size_t	i;
	size_t	n;

	n = (*mdata)->line_num;
	i = 0;
	if (n)
	{
		while (i < n)
		{
			free((*mdata)->color_m[i]);
			i++;
		}
	}
	free((*mdata)->color_m);
	return (NULL);
}

void	*clean_matrix(t_map **mdata)
{
	size_t	i;
	size_t	n;

	n = (*mdata)->line_num;
	i = 0;
	if (n)
	{
		while (i < n)
		{
			free((*mdata)->matrix[i]);
			i++;
		}
	}
	free((*mdata)->matrix);
	return (NULL);
}

int	exit_fdf(t_map **mdata, int error)
{
	if (error == 10)
	{
		ft_printf("error\n");
		return (1);
	}
	if ((*mdata)->matrix && (*mdata)->line_len > 0 && (*mdata)->line_num > 0)
	{
		clean_matrix(mdata);
	}
	if ((*mdata)->color_m && (*mdata)->line_len > 0 && (*mdata)->line_num > 0)
	{
		clean_col_matrix(mdata);
	}
	if (*mdata)
		(free(*mdata));
	if (error)
	{
		ft_printf("error\n");
		return (1);
	}
	exit (0);
	return (0);
}
