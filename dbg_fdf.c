#include "fdf.h"

void	print_map_matrix(t_map *mdata)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mdata->matrix[i])
	{
		while (mdata->matrix[i][j])
		{
			printf("%i", mdata->matrix[i][j]);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	print_pars_result(t_map *map)
{
	printf("\n***		map parsing result		***\n");
	printf("line_len:%lu\n", map->line_len);
	printf("line_num:%i\n", map->line_num);
	printf("***			***			***\n");
}
