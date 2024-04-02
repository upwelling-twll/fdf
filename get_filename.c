/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_filename.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:40:27 by nmagdano          #+#    #+#             */
/*   Updated: 2024/04/02 23:05:36 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	correct(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (!len || len <= 4)
		return (1);
	len--;
	if (file[len] == 'f' && file[len - 1] == 'd' && file[len - 2] == 'f'
		&& file[len - 3] == '.')
		return (0);
	return (1);
}

char	*get_file(char *argv)
{
	char	*file;
	int		n;

	n = 0;
	if (argv)
	{
		file = argv;
		if (correct(file))
			return (NULL);
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
