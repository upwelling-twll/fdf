#include "fdf.h"

void	*clean_matrix(t_map **mdata)
{
	size_t	i;
	size_t	n;

	printf("clean matrix\n");
	n = (*mdata)->line_num;
	i = 0;
	if (n)
	{
		while (i < n)
		{
			free((*mdata)->matrix[i]);
			i++;
		}
	}
	free((*mdata)->matrix);
	return (NULL);
}

int	exit_fdf(t_map **mdata, int error)
{
	if ((*mdata)->matrix && (*mdata)->line_len > 0 && (*mdata)->line_num > 0)
	{
		clean_matrix(mdata);
	}
	if (*mdata)
		(free(*mdata));
	if (error)
	{
		ft_printf("error\n");
		return (1);
	}
	exit (0);
	return (0);
}
