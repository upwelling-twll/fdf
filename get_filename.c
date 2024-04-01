#include "fdf.h"

char	*get_file(char *argv)
{
	char	*file;
	int		n;

	n = 0;
	if (argv)
	{
		file = argv;
		n = open(file, O_RDONLY);
		if (n > 2)
		{
			close(n);
			return (file);
		}
		if (n >= 0 && n <= 2)
			close(n);
	}
	return (NULL);
}
