#include "fdf.h"

void	clean_split(char **arr, size_t n)
{
	size_t	i;

//	printf("clean split\n");
	if (*arr)
	{
		i = 0;
		while (i < n)
		{
//			printf("arr[%lu] =%s$\n", i, *arr);
			if (*arr != NULL)
				free(*arr);
			arr++;
			i++;
		}
		//free(arr);
	}
	return ;
}

void	clean_all_split(char **arr, size_t n)
{
	size_t	i;

	i = 0;
	//printf("will del str:%s\n", arr[i]);
	if (arr[i] && n)
	{
		while (arr[i])
		{
			//printf("will del str:%s\n", arr[i]);
			free(arr[i]);
			i++;
		}
		free(arr[i]);
	}
	return ;
}
