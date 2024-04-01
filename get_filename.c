/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_filename.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:40:27 by nmagdano          #+#    #+#             */
/*   Updated: 2024/04/01 23:30:59 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*get_file(char *argv)
{
	char	*file;
	int		n;

	n = 0;
	if (argv)
	{
		file = argv;
		n = open(file, O_RDONLY);
		if (n > 2)
		{
			close(n);
			return (file);
		}
		if (n >= 0 && n <= 2)
			close(n);
	}
	return (NULL);
}
