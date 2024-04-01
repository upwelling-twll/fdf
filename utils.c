/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:40:27 by nmagdano          #+#    #+#             */
/*   Updated: 2024/04/02 01:06:56 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	min(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	max(int a, int b)
{
	if (b < a)
		return (b);
	return (a);
}

int	adapt(int zoom, t_map *mdata)
{
	float	diff;

	diff = mdata->win_wight / mdata->line_len;
	if (diff == 10 && zoom <= 4)
		return (zoom);
	else if (diff <= 4 && zoom <= 1)
		return (zoom * 2);
	if (zoom >= 1 && zoom <= 10 && diff >= 1 && diff <= 10
		&& mdata->line_len > 100)
		return (zoom * diff / 4);
	else if (zoom > 30)
		return (zoom / 2);
	return (zoom);
}
