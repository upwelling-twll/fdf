/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_events2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:40:27 by nmagdano          #+#    #+#             */
/*   Updated: 2024/04/04 15:26:35 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	identify_key2(int key)
{
	if (key == 19 || key == 20)
		return (1);
	return (0);
}

int	execute_key2(int key, t_map **mdata)
{
	if (key == 19)
		(*mdata)->two_d = 1;
	if (key == 20)
		(*mdata)->two_d = 0;
	return (0);
}
