#include "fdf.h"

int	exit_fdf(t_map **mdata, int error)
{
	if (*mdata)
		(free(*mdata));
	if (error)
	{
		write(2, "ERROR\n", 6);
		return (1);
	}	
	return (0);
}