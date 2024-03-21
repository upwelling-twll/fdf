#include "fdf.h"

void	print_map_matrix(t_map *mdata)
{
	size_t	i;
	int	j;

	i = 0;
	j = 0;
	printf("\n***		matrix		***\n");
	//printf("%i", mdata->matrix[9][9]);
	printf("%i", mdata->line_num);
	// while (i < mdata->line_num)
	// {
	// 	while (j < mdata->line_len)
	// 	{
	// 		printf("%i", mdata->matrix[i][j]);
	// 		j++;
	// 	}
	// 	write(1, "\n", 1);
	// 	i++;
	// }
}

void	print_pars_result(t_map *map)
{
	printf("\n***		map parsing result		***\n");
	printf("line_len:%lu\n", map->line_len);
	printf("line_num:%i\n", map->line_num);
	printf("***			***			***\n");
}
