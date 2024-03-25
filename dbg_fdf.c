#include "fdf.h"

void	print_line(int *line)
{
	int i = 0;

	while (i < 12)
	{
		printf("%i", line[i]);
		i++;
	}
}

void	print_map_matrix(t_map *mdata)
{
	size_t	i;

	i = 0;
	printf("\n***		matrix		***\n");
	//printf("%i", mdata->matrix[9][9]);
	printf("mdata->line_num:%i\n", mdata->line_num);
	printf("mdata->line_len:%li\n", mdata->line_len);
	while ((mdata)->matrix[i])
	{
		print_line((mdata)->matrix[i]);
		printf("\n");
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
