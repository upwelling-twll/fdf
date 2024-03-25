#include "fdf.h"

int	*split_digits(char *str, size_t len)
{
	int		*arr;
	size_t	i;

	i = 0;
	arr = malloc(sizeof(int) * (len + 1));
	while(str[i] != '\n' && str[i] != '\0')
	{
		arr[i] = str[i] - '0';
		i++;
	}
	return (arr);
}

void	save_map(int fd, t_map **mdata)
{
	char	*str;
	int		i;

	i = 0;
	(*mdata)->matrix = malloc(sizeof(int *) * ((*mdata)->line_num + 1));
	while ((str = get_next_line(fd)) != NULL)
	{
		(*mdata)->matrix[i] = split_digits(str, (*mdata)->line_len);
		free(str);
		i++;
	}
	(*mdata)->matrix[i] = NULL;
	i = 0;
	print_map_matrix(*mdata);
}
