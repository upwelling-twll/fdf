# ifndef FDF_H
# define FDF_H

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pix;
	int		line_length;
	int		endian;
}				t_data;

#endif