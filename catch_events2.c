/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_events2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:40:27 by nmagdano          #+#    #+#             */
/*   Updated: 2024/04/04 20:43:24 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	identify_key2(int key)
{
	if (key == 19 || key == 20)
		return (1);
	if (key == 35 || key == 37)
		return (1);
	if (key == 16 || key == 4)
		return (1);
	if (key == 8 || key == 7)
		return (1);
	return (0);
}

int	execute_key2(int key, t_map **mdata)
{
	if (key == 19)
		(*mdata)->two_d = 1;
	if (key == 20)
		(*mdata)->two_d = 0;
	if (key == 35)
		build_perspective(mdata);
	if (key == 37)
		(*mdata)->perspective = 0;
	if (key == 16) //yaw
		(*mdata)->yaw += 5;
	if (key == 4) //hight(pitch)
		(*mdata)->pitch += 5;
	if (key == 8) //yaw
		(*mdata)->yaw -= 5;
	if (key == 7) //hight(pitch)
		(*mdata)->pitch -= 5;
	return (0);
}
