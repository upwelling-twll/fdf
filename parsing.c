#include "fdf.h"

size_t	get_line_len(char *str)
{
	if (str && str[0] != '\0' && str[0] != '\n')
		return (ft_strlen(str));
	return (-1);
}

int	parse_map(int fd, t_map **mdata)
{
	char	*str;
	size_t	cur_len;
	int		line_num;

	line_num = 0;
	if ((str = get_next_line(fd))  != NULL)
	{
		cur_len = get_line_len(str);
		line_num = 1;
		free(str);
	}
	else
		return (1);
	while ((str = get_next_line(fd)) != NULL)
	{
		cur_len = get_line_len(str);
		free(str);
		if (cur_len != (*mdata)->line_len)
			return (1);
		line_num++;
	}
	(*mdata)->line_num = line_num;
	print_pars_result(*mdata);
	return (0);
}
