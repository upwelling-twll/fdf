#include "fdf.h"

int	get_line_num(char *file)
{
	int		fd;
	int 	n;
	char	*str;

	n = 0;
	if (fd = open(file, O_RDONLY) < 2)
		return (-1);
	while (str = get_next_line(file))
	{
		n++;
		free(str);
	}
	close(fd);
	return (n);
}

int	get_line_len(char *file)
{
	int		fd;
	int 	n;
	char	*str;
	char	**arr;

	n = 0;
	if (fd = open(file, O_RDONLY) < 2)
		return (-1);
	if (str = get_next_line(file) != NULL)
	{
		while
	}
	clode(fd);
	return (n);
}

int	parse_map(int fd, t_map **mdata)
{
	int		i;
	
	i = 0;
	*mdata = malloc(sizeof(t_map));
	if (i = get_line_num(fd) > 0)
		(*mdata)->line_num = i;
	if (i = get_line_len(fd) > 0)
		(*mdata)->line_len = i;
	else
		return (1);
	if (fill_matrix(mdata))
		return (1);
	return (0);
}

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
		printf("n=%i\n", n);
		if (n == 2 && (!ft_strncmp(fparts[1], "fdf", ft_strlen(fparts[1]))))
		{
			clean_split(fparts, n);
			return (file);
		}
		else
		{
			clean_split(fparts, n);
			return (NULL);
		}
	}
	return (NULL);
}
