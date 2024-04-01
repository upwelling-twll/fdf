#include "fdf.h"

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
	//printf("str=%s$\n", str);
	arr = fdf_split(str, c);
	if (arr && arr[0])
	{
		while (arr[i])
			i++;
		//printf("arr[i-1]=%c$,arr[i][0]=%c$\n",arr[i-1][0], arr[i][0]);
		//printf("arr[i-1]=%s$,arr[i]=%s$\n",arr[i-1], arr[i]);
		clean_split(arr, i);
	}
	if (arr)
		free(arr);
	return (i);
}

int	get_line_len(char *file)
{
	int		fd;
	char	*str;
	int		len;
	int		nlen;
	int i;

	len = 0;
	str = NULL;
	if ((fd = open(file, O_RDONLY)) <= 2)
		return (-1);
	if ((str = get_next_line(fd)) != NULL)
	{
		len = width_split(str, ' ');
		free(str);
		i = 1;
		while ((str = get_next_line(fd)) != NULL)
		{
			nlen = width_split(str, ' ');
			if (nlen != len)
			{
				free(str);
				//printf("str_len=%i (i=%i), norm_len=%i\n", nlen, i, len);
				return (-1);
			}
			free(str);
			i++;
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

int	parse_map(char *file, t_map **mdata)
{
	int		i;
	
	i = 0;
	//printf("will parse\n");
	*mdata = malloc(sizeof(t_map));
	(*mdata)->line_len = 0;
	(*mdata)->line_num = 0;
	if ((i = get_line_num(file)) > 0)
		(*mdata)->line_num = i;
	//printf("got lnum = %i\n", (*mdata)->line_num);
	if ((i = get_line_len(file)) > 0)
		(*mdata)->line_len = i;
	else
		return (1);
	if (fill_matrix(mdata, file))
		return (1);
	//printf("parse:line_len=%lu\n in parse_map:", (*mdata)->line_len);
	//print_map_matrix(*mdata);
	return (0);
}
