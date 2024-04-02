/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:40:27 by nmagdano          #+#    #+#             */
/*   Updated: 2024/04/02 18:39:40 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	ft_gethex(char *str)
{
	char			*hex;
	unsigned long	result;
	char			*ptr;

	hex = "0123456789abcdef";
	result = 0;
	str++;
	str++;
	while (*str != '\0')
	{
		ptr = ft_strchr(hex, ft_tolower(*str));
		if (ptr == NULL)
			break ;
		result = result * 16 + (ptr - hex);
		str++;
	}
	return (result);
}

int	ishex(char c)
{
	if (!(ft_strchr("abcdefABDCEF", c)))
	{
		if (('0' <= c) && (c <= '9'))
			return (0);
		else
			return (1);
	}
	return (0);
}

int	correct_hex(char *str)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	if (str == NULL || (len < 3 || len > 10))
		return (1);
	if (str[0] != '0' || (str[1] != 'x' && str[i] != 'X'))
		return (1);
	i = 2;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if ((ishex(str[i])))
			return (1);
		i++;
	}
	return (0);
}

unsigned int	check_color_matrix(char *nmbr)
{
	char			**arr;
	int				i;
	unsigned int	hex;

	i = 0;
	arr = ft_split(nmbr, ',');
	if (!arr)
		return (-1);
	while (arr[i])
		i++;
	if (i != 2 || correct_hex(arr[1]))
	{
		clean_all_split(arr, i);
		return (-1);
	}
	hex = ft_gethex(arr[1]);
	if (!hex)
	{
		clean_all_split(arr, i);
		return (-1);
	}
	clean_all_split(arr, i);
	return (hex);
}
