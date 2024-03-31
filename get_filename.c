#include "fdf.h"

char	*file_exists(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd >= 3)
		return (file);
	return (NULL); 
}

char	*get_file(char *argv)
{
	char	*file;
	char	**fparts;
	int		n;

	n = 0;
	if (argv)
	{
		file = argv;
		fparts = ft_split(file, '.');
		while (fparts[n] != NULL)
			n++;
		if (n == 2 && (!ft_strncmp(fparts[1], "fdf", ft_strlen(fparts[1]))))
		{
			clean_all_split(fparts, n);
			free(fparts);
			return (file_exists(argv));
		}
		else
		{
			clean_all_split(fparts, n);
			free(fparts);
			return (NULL);
		}
	}
	return (NULL);
}
