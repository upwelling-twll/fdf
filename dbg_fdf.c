#include "fdf.h"

void	print_line(int *line, size_t len)
{
	size_t i = 0;

	while (i < len)
	{
		printf("%3d", line[i]);
		printf(" ");
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
	printf("mdata->line_len:%lu\n", mdata->line_len);
	while ((mdata)->matrix[i])
	{
		print_line((mdata)->matrix[i], (mdata)->line_len);
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
