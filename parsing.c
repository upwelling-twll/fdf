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
		//free(arr);
	}
	return ;
}

void	clean_all_split(char **arr, size_t n)
{
	size_t	i;

	i = 0;
	printf("will del str:%s\n", arr[i]);
	if (arr[i] && n)
	{
		while (arr[i])
		{
			printf("will del str:%s\n", arr[i]);
			free(arr[i]);
			i++;
		}
		free(arr[i]);
	}
	return ;
}

int	get_line_num(char *file)
{
	int		fd;
	int 	n;
	char	*str;

	n = 0;
	if ((fd = open(file, O_RDONLY)) < 2)
		return (-1);
	while ((str = get_next_line(fd)) != NULL)
	{
		n++;
		free(str);
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
			i++;
		clean_split(arr, i);
	}
	free(arr);
	return (i);
}

int	get_line_len(char *file)
{
	int		fd;
	char	*str;
	int		len;

	if ((fd = open(file, O_RDONLY)) < 2)
		return (-1);
	if ((str = get_next_line(fd)) != NULL)
	{
		len = width_split(str, ' ');
		free(str);
		while ((str = get_next_line(fd)) != NULL)
		{
			if (width_split(str, ' ') != len)
			{
				free(str);
				return (-1);
			}
			free(str);
		}
	}
	else
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (len);
}

int	verify_num(int num)
{
	if (num < 2147483647 && num > -2147483648)
		return (0);
	return (1);
}

int	copy_to_matrix(int *mtx_line, char *str, int len)
{
	int		i;
	int		num;
	char	**nums_str;
	int		cplen;

	i = 0;
	cplen = len;
	nums_str = ft_split(str, ' ');
	while (len)
	{
		num = ft_atoi(nums_str[i]);
		if (verify_num(num))
			return(-1);
		mtx_line[i] = num;
		i++;
		len--;
	}
	printf("gonna cleanall solit\n");
	clean_all_split(nums_str, cplen);
	free(nums_str);
	return (0);
}

int	fill_matrix(t_map **mdata, char *file)
{
	int		i;
	int		fd;
	char	*str;

	i = 0;
	(*mdata)->matrix = malloc(sizeof(int*) * ((*mdata)->line_num + 1));
	while (i <= (*mdata)->line_num - 1)
	{
		(*mdata)->matrix[i] = (int*)malloc(sizeof(int) * ((*mdata)->line_len));
		i++;
	}
	i = 0;
	fd = open(file, O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		if (copy_to_matrix((*mdata)->matrix[i], str, (*mdata)->line_len))
		{
			close(fd);
			return (1);
		}
		i++;
		free(str);
	}
	(*mdata)->matrix[i] = NULL;
	close(fd);
	return (0);
}

int	parse_map(char *file, t_map **mdata)
{
	int		i;
	
	i = 0;
	printf("will parse\n");
	*mdata = malloc(sizeof(t_map));
	if ((i = get_line_num(file)) > 0)
		(*mdata)->line_num = i;
	if ((i = get_line_len(file)) > 0)
		(*mdata)->line_len = i;
	else
		return (1);
	if (fill_matrix(mdata, file))
		return (1);
	return (0);
}

char	*get_file(char *argv)
{
	char	*file;
	char	**fparts;
	int		n;

	n = 0;
	if (argv)
	{
		file = argv;
		fparts = ft_split(file, '.');
		while (fparts[n] != NULL)
			n++;
		printf("file_name_split=%i\n", n);
		if (n == 2 && (!ft_strncmp(fparts[1], "fdf", ft_strlen(fparts[1]))))
		{
			clean_all_split(fparts, n);
			free(fparts);
			return (file);
		}
		else
		{
			clean_all_split(fparts, n);
			free(fparts);
			return (NULL);
		}
	}
	return (NULL);
}
