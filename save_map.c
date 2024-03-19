#include "fdf.h"

int	*split_digits(char *str, size_t len)
{
	int		*arr;
	size_t	i;

	i = 0;
	arr = malloc(sizeof(int) * len + 1);
	printf("str=%s, len = %lu\n", str, len);
	while(str[i] != '\n')
	{
		arr[i] = str[i] - '0';
		i++;
	}
	printf("arr[i]=%i, arr[len-1]=%i\n", arr[0], arr[len-1]);
	return (arr);
}

void	save_map(int fd, t_map **mdata)
{
	char	*str;
	int		i;

	i = 0;
	(*mdata)->matrix = malloc(sizeof(int *) * ((*mdata)->line_num) + 1);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("sizeof matrix=%lu\n", sizeof((*mdata)->matrix));
		(*mdata)->matrix[i] = split_digits(str, (*mdata)->line_len);
		free(str);
		i++;
	}
	(*mdata)->matrix[i] = NULL;
}
