/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:40:27 by nmagdano          #+#    #+#             */
/*   Updated: 2024/04/01 23:30:28 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clean_split(char **arr, size_t n)
{
	size_t	i;

	if (*arr)
	{
		i = 0;
		while (i < n)
		{
			if (*arr != NULL)
				free(*arr);
			arr++;
			i++;
		}
	}
	return ;
}

void	clean_all_split(char **arr, size_t n)
{
	size_t	i;

	i = 0;
	if (arr[i] && n)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr[i]);
	}
	return ;
}
