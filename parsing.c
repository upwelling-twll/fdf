#include "fdf.h"

size_t	get_line_len(char *str)
{
	size_t	len;

	if (str && str[0] != '\0' && str[0] != '\n')
	{
		len = ft_strlen(str);
		if (str[len-1] == '\n')
			return (len-1);
		else
			return (len);
	}
	return (-1);
}

int	matrix_nums_only(char *str)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	while (i < len - 1)
	{
		if (!(ft_isdigit(str[i])))
			return (1);
		i++;
	}
	free(str);
	return (0);
}	

int	parse_map(int fd, t_map **mdata)
{
	char	*str;
	size_t	cur_len;

	if ((str = get_next_line(fd)) != NULL)
	{
		*mdata = malloc(sizeof(t_map));
		(*mdata)->line_num = 1;
		(*mdata)->line_len =  get_line_len(str);
		if ((*mdata)->line_len <= 0 || matrix_nums_only(str))
			return (1);
	}
	else
		return (1);
	while ((str = get_next_line(fd)) != NULL)
	{
		cur_len = get_line_len(str);
		if (cur_len != (*mdata)->line_len || matrix_nums_only(str))
			return (1);
		(*mdata)->line_len = cur_len;
		(*mdata)->line_num++;
	}
	print_pars_result(*mdata);
	return (0);
}

int	check_fd(int fd)
{
	if (fd <= 0)
		return (1);
	printf("fd=%i\n", fd);
	return (0);
}

char	*get_file(char *argv)
{
	char	*file;

	file = argv;
	if (argv)
		return (argv);
	return (NULL);
}
