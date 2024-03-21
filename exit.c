#include "fdf.h"

void	*clean_saved_map(t_map **mdata)
{
	size_t	i;
	//int		**arr;
	size_t	n;

	//arr = (*mdata)->matrix;
	printf("line_num in main:%i", (*mdata)->line_num);
	n = (*mdata)->line_num;
	if ((*mdata)->matrix && (*mdata)->matrix[i])
	{
		i = 0;
		while (i < n)
		{
			if ((*mdata)->matrix[i] != NULL)
				free((*mdata)->matrix[i]);
			i++;
		}
		//free(arr);
	}
	return (NULL);
}

int	exit_fdf(t_map **mdata, int error)
{
	if ((*mdata)->matrix)
		clean_saved_map(mdata);
	// printf("%p\n", *mdata);
	// 	printf("%p\n", (*mdata)->matrix);
	// if (*mdata)
	// 	(free(mdata));
	if (error)
	{
		write(2, "ERROR\n", 6);
		return (1);
	}	
	return (0);
}