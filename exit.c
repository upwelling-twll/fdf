#include "fdf.h"

void	*clean_matrix(t_map **mdata)
{
	size_t	i;
	size_t	n;

//	printf("line_num in main:%i\n", (*mdata)->line_num);
	printf("clean matrix\n");
	n = (*mdata)->line_num;
	i = 0;
	if (n)
	{
//		printf("will clean\n");
		while (i < n)
		{
//			printf("cleaning\n");
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
//		printf("matrix\n");
		clean_matrix(mdata);
	}
	// printf("%p\n", *mdata);
	// 	printf("%p\n", (*mdata)->matrix);
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